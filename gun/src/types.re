type gameStatus = NotStarted | Loading | Active | Finished;

type action = 
  | Init
  | WaitCamera
  | StartGame(string)
  | StartShooting
  | StopShooting
  | Shot(string);

type state = {
  gameStatus,
  cameraReady: bool,
  code: string,
  shooting: bool
};

type barcode = {
  .
  "type": string,
  "data": string
};
