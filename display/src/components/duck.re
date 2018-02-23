open Pixi;

type t = {
  id: int,
  top: Sprite.t,
  bottom: Sprite.t,
  filter: Filters.BlurFilter.t,
  mutable filterValues: list(int),
};

let createDuck = () => {
  let sprite = Sprite.fromImage("/duck.png");
  200 |> Sprite.setWidth(sprite);
  160 |> Sprite.setHeight(sprite);
  sprite;
};

let createFilter = filterValues => {
  let filter = Filters.BlurFilter.create();
  let blur =
    List.length(filterValues) - 1 |> List.nth(filterValues) |> float_of_int;
  blur /. 20. |> Filters.BlurFilter.setBlur(filter);
  filter;
};

let create = id => {
  let container = Container.create();
  let top = createDuck() |> Container.addChild(container);
  let bottom = createDuck() |> Container.addChild(container);
  [
    `BlurFilter(Filters.BlurFilter.create()),
    `AlphaFilter(Filters.AlphaFilter.create()),
  ]
  |> Sprite.setFilters(bottom);
  let filterValues = Lodash.range(30, 80, 1) @ Lodash.range(80, 30, -1);
  let filter = Filters.BlurFilter.create();
  {id, top, bottom, filter, filterValues};
};

let update = (background, _state, tick) => {};
