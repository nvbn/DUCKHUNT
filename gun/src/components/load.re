open BsReactNative;

let component = ReasonReact.statelessComponent("Load");

let make = (_children) => {
  ...component,

  render: (_self) => 
    <View style=Style.(style([flex(1.), justifyContent(Center), alignItems(Center)]))>
      <Text value="Waiting for camera..." />
    </View>
};
