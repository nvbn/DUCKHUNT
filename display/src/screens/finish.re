open Pixi;

type t = {container: Container.t};

let create = (session, score) => {
  let container = Container.create();
  let title = Label.create("SCORE: " ++ string_of_int(score), 100, 50, 128);
  container |> Container.addChild(title.container);
  let help = Label.create("scan with the app to start again", 400, 145, 64);
  container |> Container.addChild(help.container);
  let code = Qrcode.create(session, 400, 200, 600);
  container |> Container.addChild(code.container);
  {container: container};
};
