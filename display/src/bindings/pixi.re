module Filters = {
  module BlurFilter = {
    type t;
    [@bs.scope "filters"] [@bs.new] [@bs.module "pixi.js"]
    external create : unit => t = "BlurFilter";
    [@bs.set] external setBlur : (t, float) => unit = "blur";
  };
  module AlphaFilter = {
    type t;
    [@bs.scope "filters"] [@bs.new] [@bs.module "pixi.js"]
    external create : unit => t = "AlphaFilter";
    [@bs.set] external setAlpha : (t, float) => unit = "alpha";
  };
};

module Sprite = {
  type t;
  [@bs.scope "Sprite"] [@bs.val] [@bs.module "pixi.js"]
  external fromImage : string => t = "";
  [@bs.set] external setWidth : (t, int) => unit = "width";
  [@bs.set] external setHeight : (t, int) => unit = "height";
  [@bs.set] external setX : (t, int) => unit = "x";
  [@bs.set] external setY : (t, int) => unit = "y";
  [@bs.set] external setFilters : (t, list('filter)) => unit = "filters";
};

module Container = {
  type t;
  [@bs.new] [@bs.module "pixi.js"] external create : unit => t = "Container";
  [@bs.send]
  external addChild : (t, 'displayObject) => 'displayObject = "addChild";
  [@bs.set] external setX : (t, int) => unit = "x";
  [@bs.set] external setY : (t, int) => unit = "y";
  [@bs.set] external setFilters : (t, list('filter)) => unit = "filters";
};

module Application = {
  type t;
  [@bs.new] [@bs.module "pixi.js"]
  external create : (int, int) => t = "Application";
  [@bs.get] external view : t => Dom.element = "view";
  [@bs.get] external stage : t => Container.t = "stage";
};
