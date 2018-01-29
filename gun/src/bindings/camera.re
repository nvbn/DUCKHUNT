[@bs.module "expo"] external camera : ReasonReact.reactClass = "Camera";

let make = (~style=?, ~onBarCodeRead=?, ~cameraType=?, ~ratio=?, ~zoom=?, ~torchMode=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=camera,
    ~props=
      Js.Undefined.(
        {
          "onBarCodeRead": from_opt(onBarCodeRead),
          "style": from_opt(style),
          "type": from_opt(cameraType),
          "ratio": from_opt(ratio),
          "zoom": from_opt(zoom),
          "torchMode": from_opt(torchMode)
        }
      )
  );

let backCamera = [%bs.raw{| require('expo').Camera.Constants.Type.back |}];
