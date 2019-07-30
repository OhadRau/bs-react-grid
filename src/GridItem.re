type gridItemCallback('data) =
(~i: string,
  ~w: int,
  ~h: int,
  'data
) => unit;

[@bs.module "react-grid-layout/build/GridItem"][@react.component]
external make :
(~cols: int = ?,
  ~containerWidth: int = ?,
  ~margin: (int, int) = ?,
  ~containerPadding: (int, int) = ?,
  ~rowHeight: int = ?,
  ~maxRows: int = ?,
  ~isDraggable: bool = ?,
  ~isResizable: bool = ?,
  ~static: bool = ?,
  ~useCSSTransforms: bool = ?,
  ~usePercentages: bool = ?,

  ~className: string = ?,
  ~style: Js.t({..}) = ?,
  ~cancel: string = ?,
  ~handle: string = ?,

  ~x: int = ?,
  ~y: int = ?,
  ~w: int = ?,
  ~h: int = ?,

  ~minW: int = ?,
  ~maxW: int = ?,
  ~minH: int = ?,
  ~maxH: int = ?,
  ~i: string = ?,

  ~onDrag: gridItemCallback(ReactGrid.gridDragEvent) = ?,
  ~onDragStart: gridItemCallback(ReactGrid.gridDragEvent) = ?,
  ~onDragStop: gridItemCallback(ReactGrid.gridDragEvent) = ?,
  ~onResize: gridItemCallback(ReactGrid.gridResizeEvent) = ?,
  ~onResizeStart: gridItemCallback(ReactGrid.gridResizeEvent) = ?,
  ~onResizeStop: gridItemCallback(ReactGrid.gridResizeEvent) = ?,
  ~children: React.element = ?
) => React.element = "default";