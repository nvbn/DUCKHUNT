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

let setIntVal: (string, int) => unit = [%bs.raw{|
function setIntVal(key, val) {
  firebase.database().ref(key).set(val);
}
|}];

let setStringVal: (string, string) => unit = [%bs.raw{|
  function setStringVal(key, val) {
    firebase.database().ref(key).set(val);
  }
|}];
