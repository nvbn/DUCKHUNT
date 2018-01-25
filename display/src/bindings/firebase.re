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

let onIntValue: ((int) => unit, string) => unit = [%bs.raw{|
function onValue(callback, key) {
  console.log(key);

  firebase.database().ref(key).on('value', function(snapshot) {
    callback(snapshot.val());
  });
}
|}];

let onStringValue: ((string) => unit, string) => unit = [%bs.raw{|
  function onValue(callback, key) {
    console.log(key);
  
    firebase.database().ref(key).on('value', function(snapshot) {
      callback(snapshot.val());
    });
  }
|}];
