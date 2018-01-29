type options = {
  .
  "apiKey": string,
  "authDomain": string,
  "databaseURL": string,
  "projectId": string
};

let initializeApp : (options) => unit = [%bs.raw{|
function initializeApp(options) {
  window.firebase = require('firebase');

  firebase.initializeApp(options);
}
|}];
