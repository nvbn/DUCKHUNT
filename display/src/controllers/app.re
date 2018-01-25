open Types;
open UUID;

let component = ReasonReact.reducerComponent("App");

let firebase = Firebase.initializeApp(Config.firebase);

let getDucks = () => {
  let width = Browser.getWidth();
  let height = Browser.getHeight();

  [
    {x: 100, y: 100, id: uuid(), direction: Right},
    {x: 100 + width / 2, y: 250, id: uuid(), direction: Right},
    {x: 300, y: 150 + height / 3, id:  uuid(), direction: Left},
    {x: 300 + width / 2, y: 300 + height / 3, id: uuid(), direction: Left}
  ]
};

let waitForStart = (send, code) =>
  "game/" ++ code ++ "/start" |> Firebase.onIntValue((value) => if (value > 0) send(StartGame));

let handleShooting = (send, code) => 
  "game/" ++ code ++ "/shooting" |> Firebase.onIntValue((value) =>
    if (value == 1) send(StartShooting)
    else if (value == 0) send(StopShooting)
  );

let handleKills = (send, code) =>
  "game/" ++ code ++ "/kill" |> Firebase.onStringValue((value) => send(Kill(value)));

let make = (_children) => {
  ...component,

  initialState: () => {
    gameStatus: NotStarted,
    ducks: [],
    code: uuid(),
    shooting: false,
    score: 0
  },

  didMount: ({send}) => {
    Js.Global.setInterval(() => Browser.requestAnimationFrame(() => send(Tick)), 50) |> ignore;

    send(Init);

    ReasonReact.NoUpdate
  },

  reducer: (action : action, state : state) =>
    switch(action) {
    | Init => ReasonReact.SideEffects(({send}) => state.code |> waitForStart(send))

    | Tick => if (state.gameStatus == Active && !state.shooting) {
        let ducks = state.ducks |> List.map(duck => 
          switch (duck.direction) {
          | Left =>
            if (duck.x - 5 < 0) {
              {...duck, direction: Right, x: duck.x + 5}
            } else {
              {...duck, x: duck.x - 5}
            }
          | Right =>
            if (duck.x + 195 > Browser.getWidth()) {
              {...duck, direction: Left, x: duck.x - 5}
            } else {
              {...duck, x: duck.x + 5}
            }
          }
        );

        ReasonReact.Update({...state, ducks})
      } else {
        ReasonReact.NoUpdate
      }

    | StartGame => ReasonReact.UpdateWithSideEffects({
      ...state,
      gameStatus: Active,
      score: 0,
      ducks: getDucks()
    }, ({send}) => {
      state.code |> handleShooting(send);
      state.code |> handleKills(send);
    })

    | StartShooting => ReasonReact.Update({...state, shooting: true})

    | Kill(duckId) => {
      let ducks = state.ducks |> List.filter(duck => duck.id != duckId);
      let score = state.score + 25;

      if (ducks |> List.length == 0) {
        ReasonReact.Update({...state, gameStatus: Finished, score, ducks})  
      } else {
        ReasonReact.Update({...state, score, ducks})
      }
    }

    | StopShooting => ReasonReact.Update({...state, shooting: false})
    },

  render: ({state}) => {
    let { gameStatus, ducks, code, shooting, score } = state;

    switch (gameStatus) {
    | NotStarted => <Start code />
    | Active => <Battle score ducks shooting />
    | Finished => <End score code />
    }
  }
};
