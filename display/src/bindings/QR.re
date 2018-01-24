[@bs.module] external qrCode : ReasonReact.reactClass = "qrcode.react";

let make = (~value, ~size, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=qrCode,
    ~props={
      "value": value,
      "size": size
    },
    children
  );
};
