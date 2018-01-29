open BsReactNative;
open Types;

let component = ReasonReact.statelessComponent("Start");

let make = (~startGame, _children) => {
  ...component,

  render: (_self) => {
    <View style=Style.(style([flex(1.), justifyContent(Center), alignItems(Center)]))>
      <Text value="Scan QR code to start" />
      <Camera
        style=Style.(style([height(Pt(400.)), width(Pt(400.))]))
        onBarCodeRead={ (code) => startGame(code##data) }
        ratio="1:1"
        key="camera-start"
      />
    </View>
  }
};
