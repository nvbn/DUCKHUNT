type t;

[@bs.new] [@bs.module] external create : 'config => t = "qrious";

[@bs.send] external toDataURL : t => string = "toDataURL";
