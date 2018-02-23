open Pixi;

type t = {
  container: Container.t,
  filter: Filters.AlphaFilter.t,
  mutable filterValues: list(int),
};

let createLayer = (width, height) => {
  let container = Container.create();
  for (x in 0 to width / 70 + 1) {
    for (y in 0 to height / 70 + 1) {
      let sprite = Sprite.fromImage("/water.png");
      Sprite.setX(sprite, x * 70);
      Sprite.setY(sprite, y * 70);
      container |> Container.addChild(sprite);
    };
  };
  container;
};

let createFilter = filterValues => {
  let filter = Filters.AlphaFilter.create();
  let alpha =
    List.length(filterValues) - 1 |> List.nth(filterValues) |> float_of_int;
  alpha /. 100. |> Filters.AlphaFilter.setAlpha(filter);
  filter;
};

let create = (width, height) => {
  let container = Container.create();
  let bottom = createLayer(width, height);
  container |> Container.addChild(bottom);
  let top = createLayer(width, height);
  container |> Container.addChild(top);
  Container.setX(top, 10);
  let filterValues = Lodash.range(0, 100, 5) @ Lodash.range(100, 0, -5);
  let filter = createFilter(filterValues);
  [filter] |> Container.setFilters(top);
  {filterValues, container, filter};
};

let update = (background, _state, tick) =>
  if (tick mod 4 != 0) {
    switch (background.filterValues) {
    | [current, ...rest] =>
      background.filterValues = List.append(rest, [current]);
      float_of_int(current)
      /. 100.
      |> Filters.AlphaFilter.setAlpha(background.filter);
    | _ => ()
    };
  };
