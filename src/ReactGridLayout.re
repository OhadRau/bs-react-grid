[@bs.deriving jsConverter]
type compactType = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"]   `Vertical
];

[@bs.module "react-grid-layout/build/ReactGridLayout"][@react.component]
external make :
  (~className: string = ?,
    ~style: Js.t({.. }) = ?,
    ~width: int = ?,
    ~autoSize: bool = ?,
    ~cols: int = ?,
    ~draggableCancel: string = ?,
    ~draggableHandle: string = ?,
    ~verticalCompact: bool = ?,
    ~compactType: compactType = ?,
    ~layout: ReactGrid.layout = ?,
    ~margin: (int, int) = ?,
    ~containerPadding: Js.Nullable.t((int, int)) = ?,
    ~rowHeight: int = ?,
    ~maxRows: int = ?,
    ~isDraggable: bool = ?,
    ~isResizable: bool = ?,
    ~preventCollision: bool = ?,
    ~useCSSTransforms: bool = ?,

    ~onLayoutChange: (ReactGrid.layout) => unit = ?,
    ~onDrag: ReactGrid.eventCallback = ?,
    ~onDragStart: ReactGrid.eventCallback = ?,
    ~onDragStop: ReactGrid.eventCallback = ?,
    ~onResize: ReactGrid.eventCallback = ?,
    ~onResizeStart: ReactGrid.eventCallback = ?,
    ~onResizeStop: ReactGrid.eventCallback = ?,
    ~children: React.element = ?
  ) => React.element = "default";