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

let initLabel = () => {
  let label = Label.create("DUCKHUNT", 20, 30, "64px");
  app |> Application.stage |> Container.addChild(label.container);
};

Js.Global.setTimeout(initLabel, 1000);

let code = Qrcode.create("Test", 100, 100, 300);

app |> Application.stage |> Container.addChild(code.container);

let tick = ref(0);

let update = () => {
  Background.update(background, (), tick^);
  tick := tick^ + 1;
};
/* Js.Global.setInterval(update, 20) |> ignore; */
