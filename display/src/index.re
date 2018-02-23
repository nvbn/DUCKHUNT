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

background.container |> Container.addChild(app |> Application.stage) |> ignore;

let tick = ref(0);

let update = () => {
  Background.update(background, (), tick^);
  tick := tick^ + 1;
};

Js.Global.setInterval(update, 20) |> ignore;