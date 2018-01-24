open Types;

[%bs.raw {|require('./styles.css')|}];

let component = ReasonReact.statelessComponent("Battle");

let make = (~ducks, ~score, ~shooting, _children) => {
  ...component,
  render: (_self) => {
    let placedDucks = ducks  |> List.map(duck =>
      <Duck shooting=shooting duck=duck key=duck.id />
    );

    <div className="display">
      <span className="score">
        {ReasonReact.stringToElement("score ")}
        {ReasonReact.stringToElement(string_of_int(score))}
      </span>
      <div className="ducks-area">
        (ReasonReact.arrayToElement(Array.of_list(placedDucks)))
      </div>
    </div>
  }
};
