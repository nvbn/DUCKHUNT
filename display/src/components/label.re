open Pixi;

type t = {container: Container.t};

let getStyle = size => {
  "fontFamily": "VT323",
  "fontSize": size,
  "dropShadow": 1,
  "fill": "yellow",
};

let create = (txt, x, y, size) => {
  let container = Container.create();
  let style = getStyle(size);
  let text = Text.create(txt, style);
  container |> Container.addChild(text);
  Text.setX(text, x);
  Text.setY(text, y);
  container;
};
