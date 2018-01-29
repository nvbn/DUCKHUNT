let requestCamera : ((bool) => unit) => unit = [%bs.raw{|
  function requestCamera(callback) {
    var expo = require('expo');

    expo.Permissions.askAsync(expo.Permissions.CAMERA).then(function(response){
      callback(response.status);
    });
  }
|}];
