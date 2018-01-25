type direction = Left | Right;

type duck = {x: int, y: int, id: string, direction};

type gameStatus = NotStarted | Active | Finished;

type action =
  | Init
  | Tick
  | StartGame
  | StartShooting
  | Kill(string)
  | StopShooting;

type state = {
  gameStatus,
  ducks: list (duck),
  shooting: bool,
  score: int,
  code: string
};
