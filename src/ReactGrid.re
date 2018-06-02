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
  "e": ReactEventRe.synthetic(Js.t({.})),
  "node": Dom.htmlElement,
  "newPosition": partialPosition
};

type gridResizeEvent = {.
  "e": ReactEventRe.synthetic(Js.t({.})),
  "node": Dom.htmlElement,
  "size": size
};

type eventCallback =
  (layout,
   ~oldItem: Js.Nullable.t(layoutItem),
   ~newItem: Js.Nullable.t(layoutItem),
   ~placeholder: Js.Nullable.t(layoutItem),
   ReactEventRe.synthetic(Js.t({.})),
   Dom.htmlElement
  ) => unit;

module GridItem = {
  type gridItemCallback('data) =
    (~i: string,
     ~w: int,
     ~h: int,
     'data
    ) => unit;

  [@bs.module "react-grid-layout"]
  external reactClass : ReasonReact.reactClass = "GridItem";

  let make =
    (~cols: option(int) = ?,
     ~containerWidth: option(int) = ?,
     ~margin: option((int, int)) = ?,
     ~containerPadding: option((int, int)) = ?,
     ~rowHeight: option(int) = ?,
     ~maxRows: option(int) = ?,
     ~isDraggable: option(bool) = ?,
     ~isResizable: option(bool) = ?,
     ~static: option(bool) = ?,
     ~useCSSTransforms: option(bool) = ?,
     ~usePercentages: option(bool) = ?,

     ~className: option(string) = ?,
     ~style: option(Js.t({..})) = ?,
     ~cancel: option(string) = ?,
     ~handle: option(string) = ?,

     ~x: option(int) = ?,
     ~y: option(int) = ?,
     ~w: option(int) = ?,
     ~h: option(int) = ?,

     ~minW: option(int) = ?,
     ~maxW: option(int) = ?,
     ~minH: option(int) = ?,
     ~maxH: option(int) = ?,
     ~i: option(string) = ?,

     ~onDrag: option(gridItemCallback(gridDragEvent)) = ?,
     ~onDragStart: option(gridItemCallback(gridDragEvent)) = ?,
     ~onDragStop: option(gridItemCallback(gridDragEvent)) = ?,
     ~onResize: option(gridItemCallback(gridResizeEvent)) = ?,
     ~onResizeStart: option(gridItemCallback(gridResizeEvent)) = ?,
     ~onResizeStop: option(gridItemCallback(gridResizeEvent)) = ?
    ) =>
    ReasonReact.wrapJsForReason
      (~reactClass,
       ~props=Js.Nullable.({
         "cols": fromOption(cols),
         "containerWidth": fromOption(containerWidth),
         "margin": fromOption(margin),
         "containerPadding": fromOption(containerPadding),
         "rowHeight": fromOption(rowHeight),
         "maxRows": fromOption(maxRows),
         "isDraggable": fromOption(isDraggable),
         "isResizable": fromOption(isResizable),
         "static": fromOption(static),
         "useCSSTransforms": fromOption(useCSSTransforms),
         "usePercentages": fromOption(usePercentages),

         "className": fromOption(className),
         "style": fromOption(style),
         "cancel": fromOption(cancel),
         "handle": fromOption(handle),

         "x": fromOption(x),
         "y": fromOption(y),
         "w": fromOption(w),
         "h": fromOption(h),

         "minW": fromOption(minW),
         "maxW": fromOption(maxW),
         "minH": fromOption(minH),
         "maxH": fromOption(maxH),
         "i": fromOption(i),

         "onDrag": fromOption(onDrag),
         "onDragStart": fromOption(onDragStart),
         "onDragStop": fromOption(onDragStop),
         "onResize": fromOption(onResize),
         "onResizeStart": fromOption(onResizeStart),
         "onResizeStop": fromOption(onResizeStop)
       })
      );
};

module ReactGridLayout = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "react-grid-layout";

  [@bs.deriving jsConverter]
  type compactType = [
    | [@bs.as "horizontal"] `Horizontal
    | [@bs.as "vertical"]   `Vertical
  ];

  let make =
    (~className: option(string) = ?,
     ~style: option(Js.t({.. })) = ?,
     ~width: option(int) = ?,
     ~autoSize: option(bool) = ?,
     ~cols: option(int) = ?,
     ~draggableCancel: option(string) = ?,
     ~draggableHandle: option(string) = ?,
     ~verticalCompact: option(bool) = ?,
     ~compactType: option(compactType) = ?,
     ~layout: option(layout) = ?,
     ~margin: option((int, int)) = ?,
     ~containerPadding: option(Js.Nullable.t((int, int))) = ?,
     ~rowHeight: option(int) = ?,
     ~maxRows: option(int) = ?,
     ~isDraggable: option(bool) = ?,
     ~isResizable: option(bool) = ?,
     ~preventCollision: option(bool) = ?,
     ~useCSSTransforms: option(bool) = ?,

     ~onLayoutChange: option((layout) => unit) = ?,
     ~onDrag: option(eventCallback) = ?,
     ~onDragStart: option(eventCallback) = ?,
     ~onDragStop: option(eventCallback) = ?,
     ~onResize: option(eventCallback) = ?,
     ~onResizeStart: option(eventCallback) = ?,
     ~onResizeStop: option(eventCallback) = ?
    ) =>
    ReasonReact.wrapJsForReason
      (~reactClass,
       ~props=Js.Nullable.({
          "className": fromOption(className),
          "style": fromOption(style),
          "width": fromOption(width),
          "autoSize": fromOption(autoSize),
          "cols": fromOption(cols),
          "draggableCancel": fromOption(draggableCancel),
          "draggableHandle": fromOption(draggableHandle),
          "verticalCompact": fromOption(verticalCompact),
          "compactType": fromOption(compactType),
          "layout": fromOption(layout),
          "margin": fromOption(margin),
          "containerPadding": fromOption(containerPadding),
          "rowHeight": fromOption(rowHeight),
          "maxRows": fromOption(maxRows),
          "isDraggable": fromOption(isDraggable),
          "isResizable": fromOption(isResizable),
          "preventCollision": fromOption(preventCollision),
          "useCSSTransforms": fromOption(useCSSTransforms),

          "onLayoutChange": fromOption(onLayoutChange),
          "onDrag": fromOption(onDrag),
          "onDragStart": fromOption(onDragStart),
          "onDragStop": fromOption(onDragStop),
          "onResize": fromOption(onResize),
          "onResizeStart": fromOption(onResizeStart),
          "onResizeStop": fromOption(onResizeStop)
        })
      );
};

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

module ResponsiveReactGridLayout = {
  [@bs.module "react-grid-layout"]
  external reactClass : ReasonReact.reactClass = "Responsive";

  let make =
    (~breakpoint: option(string) = ?,
     /* breakpoint => int */
     ~breakpoints: option(Js.t({..})) = ?,
     /* breakpoint => int */
     ~cols: option(Js.t({..})) = ?,
     /* breakpoint => layout */
     ~layout: option(Js.t({..})) = ?,
     ~width: int,

     ~onBreakpointChange: option((string, ~cols: int, unit) => unit) = ?,
     ~onLayoutChange: option((layout, Js.t({..})) => unit) = ?,
     ~onWidthChange: option(
      (~containerWidth: int,
       ~margin: (int, int),
       ~cols: int,
       ~containerPadding: Js.Nullable.t((int, int)),
       unit
      ) => unit
     ) = ?
    ) =>
    ReasonReact.wrapJsForReason
      (~reactClass,
       ~props=Js.Nullable.({
         "breakpoint": fromOption(breakpoint),
         "breakpoints": fromOption(breakpoints),
         "cols": fromOption(cols),
         "layout": fromOption(layout),
         "width": width,
         "onBreakpointChange": fromOption(onBreakpointChange),
         "onLayoutChange": fromOption(onLayoutChange),
         "onWidthChange": fromOption(onWidthChange)
       })
      );
};

module WidthProvider = {
  [@bs.module "react-grid-layout"]
  external reactClass: ReasonReact.reactClass = "WidthProvider";

  let make =
    (~className: option(string) = ?,
     ~measureBeforeMount: bool,
     ~style: option(Js.t({..})) = ?
    ) =>
    ReasonReact.wrapJsForReason
      (~reactClass,
       ~props=Js.Nullable.({
         "className": fromOption(className),
         "measureBeforeMount": measureBeforeMount,
         "style": fromOption(style)
       })
      );
};
