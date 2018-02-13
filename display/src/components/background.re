open Pixi;

type t = {
  bottom: Container.t,
  top: Container.t,
  container: Container.t,
  filter: Filters.AlphaFilter.t,
  mutable filterValues: list(int),
};

let generate = (width, height) => {
  let container = Container.create();
  for (x in 0 to width / 70 + 1) {
    for (y in 0 to height / 70 + 1) {
      let sprite = Sprite.fromImage("/water.png");
      Sprite.setX(sprite, x * 70);
      Sprite.setY(sprite, y * 70);
      Container.addChild(container, sprite);
    };
  };
  container;
};

let make = (~width, ~height) => {
  let top = generate(width, height);
  let bottom = generate(width, height);
  Container.setX(top, 10);
  let filterValues = Lodash.range(0, 100, 5) @ Lodash.range(100, 0, -5);
  Js.log(filterValues);
  let filter = Filters.AlphaFilter.create();
  let alpha =
    List.length(filterValues)
    - 1
    |> List.nth(filterValues)
    |> Browser.parseFloat;
  Filters.AlphaFilter.setAlpha(filter, alpha /. 100.);
  Container.setFilters(top, [filter]);
  let container = Container.create();
  Container.addChild(container, bottom);
  Container.addChild(container, top);
  {bottom, top, filterValues, container, filter};
};

let update = (background, _state, tick) =>
  if (tick mod 4 != 0) {
    let [current, ...rest] = background.filterValues;
    background.filterValues = List.append(rest, [current]);
    let alpha = Browser.parseFloat(current) /. 100.;
    Filters.AlphaFilter.setAlpha(background.filter, alpha);
  };