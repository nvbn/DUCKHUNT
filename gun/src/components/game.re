open BsReactNative;
open Types;

let component = ReasonReact.statelessComponent("Game");

let make = (~shoot, ~onShot, _children) => {
  ...component,

  render: (_self) => {
    <View style=Style.(style([flex(1.), justifyContent(Center), alignItems(Center)]))>
      <Camera
        style=Style.(style([height(Pt(400.)), width(Pt(400.))]))
        onBarCodeRead={ (code) => onShot(code##data) }
        key="camera-game"
        ratio="1:1"
        zoom=0.2
      />
      <Button title="Shoot!" onPress=shoot />
    </View>
  }
};
