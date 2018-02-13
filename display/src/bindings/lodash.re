[@bs.val] [@bs.module "lodash"]
external rangeArray : (int, int, int) => array(int) = "range";

let range = (start, stop, step) =>
  Array.to_list(rangeArray(start, stop, step));