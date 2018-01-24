type direction = Left | Right;

type duck = {x: int, y: int, id: string, direction};

type gameStatus = NotStarted | Active | Finished;

type action =
  | Tick
  | StartGame
  | StartShooting
  | Kill(string)
  | Miss;

type state = {
  gameStatus,
  ducks: list (duck),
  shooting: bool,
  score: int
};
