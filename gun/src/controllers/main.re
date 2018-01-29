open BsReactNative;
open Types;

let component = ReasonReact.reducerComponent("App");

let firebase = Firebase.initializeApp(Config.firebase);

let make = (_children) => {
  ...component,

  initialState: () => {
    gameStatus: NotStarted,
    code: "",
    cameraReady: false,
    shooting: false
  },

  didMount: ({send}) => {
    Permissions.requestCamera((_granted) => send(Init));

    ReasonReact.NoUpdate
  },

  reducer: (action : action, state : state) => {
    switch(action) {
    | Init => ReasonReact.Update({...state, cameraReady: true})

    | StartGame(code) => ReasonReact.UpdateWithSideEffects({
        ...state,
        gameStatus: Loading,
        code: code
      }, ({send}) =>  {
        Firebase.setIntVal("game/" ++ code ++ "/start", 1);
        Js.Global.setTimeout(() => send(WaitCamera), 1000) |> ignore;
      })

    | WaitCamera => ReasonReact.Update({
      ...state,
      gameStatus: Active
    })

    | StartShooting => ReasonReact.UpdateWithSideEffects({
        ...state,
        shooting: true
      }, ({send}) =>  {
        Firebase.setIntVal("game/" ++ state.code ++ "/shooting", 1);
        Js.Global.setTimeout(() => send(StopShooting), 300) |> ignore;
      })

    | StopShooting => ReasonReact.UpdateWithSideEffects({
        ...state,
        shooting: false
      }, ({send}) =>  {
        Firebase.setIntVal("game/" ++ state.code ++ "/shooting", 0);
      })

    | Shot(code) => ReasonReact.UpdateWithSideEffects({
        ...state,
        shooting: false
      }, ({send}) =>  {
        Firebase.setIntVal("game/" ++ state.code ++ "/shooting", 0);
        Firebase.setStringVal("game/" ++ state.code ++ "/kill", code);
      })
    }
  },

  render: ({state, send}) => {
    let {gameStatus, cameraReady, shooting} = state;

    if (!state.cameraReady) {
      <Load />
    } else switch(gameStatus) {
    | NotStarted => <Start startGame={ (code) => send(StartGame(code)) |> ignore } />
    | Active => <Game
        shoot={() => if (!shooting) send(StartShooting)}
        onShot={(code) => if (shooting) send(Shot(code))}
      />
    | Loading => <Load />
    }
    /* <View style=Style.(style([flex(1.), justifyContent(Center), alignItems(Center)]))>{
      if (state.cameraReady)
        <View>
          <Camera
            style=Style.(style([height(Pt(400.)), width(Pt(400.))]))
            cameraType=Camera.backCamera
            ratio="1:1"
            zoom=3
          >
            <View style=Style.(style([flex(1.)]))></View>
          </Camera>
          <Button title="Shoot!" />
        </View>
      else
          <Text value="Waiting for camera..." />
    }</View> */
  }
};
