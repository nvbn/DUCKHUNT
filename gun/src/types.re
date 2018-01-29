type gameStatus = NotStarted | Active | Finished;

type action = 
  | Init;

type state = {
  gameStatus,
  cameraReady: bool
};
