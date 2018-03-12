open Webapi;

open Pixi;

let width = Dom.window |> Dom.Window.innerWidth;

let height = Dom.window |> Dom.Window.innerHeight;

let app = Application.create(width, height);

let body =
  Dom.document
  |> Dom.Document.getElementsByTagName("body")
  |> Dom.HtmlCollection.item(0);

switch (body) {
| Some(body') => body' |> Dom.Element.appendChild(app |> Application.view)
| None => Js.log("Can't start app!")
};

let background = Background.create(width, height);

app |> Application.stage |> Container.addChild(background.container) |> ignore;

let init = () => {
  let start = Start.create("sessin");
  app |> Application.stage |> Container.addChild(start.container);
};

Js.Global.setTimeout(init, 1000);

let tick = ref(0);

let update = () => {
  Background.update(background, (), tick^);
  tick := tick^ + 1;
};

Js.Global.setInterval(update, 50) |> ignore;
