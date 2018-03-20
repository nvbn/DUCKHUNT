type gameStatus =
  | NotStarted
  | Active
  | Finished;

type t = {
  gameStatus,
  session: string,
  score: int,
};
