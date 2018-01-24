open Types;
open UUID;

let component = ReasonReact.reducerComponent("App");

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

let make = (_children) => {
  ...component,

  initialState: () => {
    gameStatus: Active,
    ducks: getDucks(),
    code: uuid(),
    shooting: false,
    score: 0
  },

  didMount: ({send}) => {
    Js.Global.setInterval(() => Browser.requestAnimationFrame(() => send(Tick)), 50);

    ReasonReact.NoUpdate
  },

  reducer: (action : action, state : state) =>
    switch(action) {
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

    | StartGame => ReasonReact.Update({
      ...state,
      gameStatus: Active,
      score: 0,
      ducks: getDucks()
    })

    | StartShooting => ReasonReact.Update({...state, shooting: true})

    | Kill(duckId) => {
      let ducks = state.ducks |> List.filter(duck => duck.id != duckId);
      let score = state.score + 25;
      let shooting = false;

      if (ducks |> List.length == 0) {
        ReasonReact.Update({...state, gameStatus: Finished, shooting, score, ducks})  
      } else {
        ReasonReact.Update({...state, shooting, score, ducks})
      }
    }

    | Miss => ReasonReact.Update({...state, shooting: false})
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
