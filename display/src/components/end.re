[%bs.raw {|require('./styles.css')|}];

let component = ReasonReact.statelessComponent("Start");

let make = (~code, ~score, _children) => {
  ...component,
  render: (_self) =>
    <div className="display">
      <span className="title">
        {ReasonReact.stringToElement("score ")}
        {ReasonReact.stringToElement(string_of_int(score))}
        {ReasonReact.stringToElement("! scan to start again")}
      </span>
      <div className="start-code">
        <QR value=code size=500 />
      </div>
    </div>
};
