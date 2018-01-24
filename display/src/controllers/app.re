open Types;

let component = ReasonReact.statelessComponent("App");

let ducks = [
  {x: 100, y: 100, id: "a", direction: Right},
  {x: 300, y: 300, id: "b", direction: Right}
];

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Battle score=100 ducks shooting=false />
};
