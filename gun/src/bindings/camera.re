[@bs.module "expo"] external button : ReasonReact.reactClass = "Camera";

let make = (~style=?, ~onBarCodeRead=?, ~cameraType=?, ~ratio=?, ~zoom=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=button,
    ~props=
      Js.Undefined.(
        {
          "onBarCodeRead": from_opt(onBarCodeRead),
          "style": from_opt(style),
          "type": from_opt(cameraType),
          "ratio": from_opt(ratio),
          "zoom": from_opt(zoom)
        }
      )
  );

let backCamera = [%bs.raw{| require('expo').Camera.Constants.Type.back |}];
