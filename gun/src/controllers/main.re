open BsReactNative;
open Types;

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

  initialState: () => {
    gameStatus: NotStarted,
    cameraReady: false
  },

  didMount: ({send}) => {
    Permissions.requestCamera((_granted) => send(Init));

    ReasonReact.NoUpdate
  },

  reducer: (action : action, state : state) => {
    switch(action) {
    | Init => ReasonReact.Update({...state, cameraReady: true})
    }
  },

  render: ({state}) => {
    <View style=Style.(style([flex(1.), justifyContent(Center), alignItems(Center)]))>{
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
    }</View>
  }
};
