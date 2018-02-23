type firebaseConfig = {
  apiKey: string,
  authDomain: string,
  databaseURL: string,
  projectId: string,
};

type gameStatus =
  | NotStarted
  | Active
  | Finished;

type state = {gameStatus};
