[%bs.raw {|require('./styles.css')|}];

let component = ReasonReact.statelessComponent("Start");

let make = (~code, _children) => {
  ...component,
  render: (_self) =>
    <div className="display">
      <span className="title">
        {ReasonReact.stringToElement("scan code with ")}
        <a href="#">{ReasonReact.stringToElement("app")}</a>
        {ReasonReact.stringToElement(" to start")}
      </span>
      <div className="start-code">
        <QR value=code size=500 />
      </div>
    </div>
};
