open Pixi;

type t = {container: Container.t};

let create = (value, x, y, size) => {
  let container = Container.create();
  Container.setX(container, x);
  Container.setY(container, y);
  let code = Qrious.create({"size": size, "value": value});
  let sprite = code |> Qrious.toDataURL |> Sprite.fromImage;
  Container.addChild(sprite, container);
  {container: container};
};
