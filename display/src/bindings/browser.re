[@bs.val] external requestAnimationFrame : (unit => unit) => unit = "";

let getWidth = () => [%bs.raw {| window.innerWidth |}];
let getHeight = () => [%bs.raw {| window.innerHeight |}];
