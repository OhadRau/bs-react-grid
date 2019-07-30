type layoutItem = {.
  "w": int,
  "h": int,
  "x": int,
  "y": int,
  "i": string,
  "minW": Js.Nullable.t(int),
  "maxW": Js.Nullable.t(int),
  "minH": Js.Nullable.t(int),
  "maxH": Js.Nullable.t(int),
  "moved": Js.Nullable.t(bool),
  "static": Js.Nullable.t(bool),
  "isDraggable": Js.Nullable.t(bool),
  "isResizable": Js.Nullable.t(bool)
};

let layout(~w, ~h, ~x, ~y, ~i, ~minW=?, ~maxW=?, ~minH=?, ~maxH=?,
           ~moved=?, ~static=?, ~isDraggable=?, ~isResizable=?, ()) {
  "w": w,
  "h": h,
  "x": x,
  "y": y,
  "i": i,
  "minW": Js.Nullable.fromOption(minW),
  "maxW": Js.Nullable.fromOption(maxW),
  "minH": Js.Nullable.fromOption(minH),
  "maxH": Js.Nullable.fromOption(maxH),
  "moved": Js.Nullable.fromOption(moved),
  "static": Js.Nullable.fromOption(static),
  "isDraggable": Js.Nullable.fromOption(isDraggable),
  "isResizable": Js.Nullable.fromOption(isResizable)
};

type layout = Js.Array.t(layoutItem);

type partialPosition = {.
  "left": int,
  "top": int
};

type size = {.
  "width": int,
  "height": int
};

type gridDragEvent = {.
  "e": ReactEvent.synthetic(Js.t({.})),
  "node": Dom.htmlElement,
  "newPosition": partialPosition
};

type gridResizeEvent = {.
  "e": ReactEvent.synthetic(Js.t({.})),
  "node": Dom.htmlElement,
  "size": size
};

type eventCallback =
  (layout,
   ~oldItem: Js.Nullable.t(layoutItem),
   ~newItem: Js.Nullable.t(layoutItem),
   ~placeholder: Js.Nullable.t(layoutItem),
   ReactEvent.synthetic(Js.t({.})),
   Dom.htmlElement
  ) => unit;
/** Fake types, included for documentation purposes:
[type breakpoint = [
  | `lg
  | `md
  | `sm
  | `xs
  | `xxs
] [@bs.string];]

[type breakpoint('a) = {.
  "lg"?: 'a,
  "md"?: 'a,
  "sm"?: 'a,
  "xs"?: 'a,
  "xxs?": 'a
};] */