open Types;

[@bs.module] external image : string = "./duck.png";

let component = ReasonReact.statelessComponent("Duck");

let make = (~duck, ~shooting, _children) => {
  ...component,
  render: (_self) => {
    let position = ReactDOMRe.Style.make(
      ~top=string_of_int(duck.y) ++ "px",
      ~left=string_of_int(duck.x) ++ "px",
      ()
    );

    <div className="duck" style=position>
      {
        if (shooting) {
          <QR value=duck.id size=200 />
        } else {
          <img src=image />
        }
      }
    </div>
  }
};
