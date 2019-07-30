[@bs.module "react-grid-layout"][@react.component]
external make :
  (~breakpoint: (string) = ?,
    /* breakpoint => int */
    ~breakpoints: (Js.t({..})) = ?,
    /* breakpoint => int */
    ~cols: (Js.t({..})) = ?,
    /* breakpoint => layout */
    ~layout: (Js.t({..})) = ?,
    ~width: int,

    ~onBreakpointChange: ((string, ~cols: int, unit) => unit) = ?,
    ~onLayoutChange: ((ReactGrid.layout, Js.t({..})) => unit) = ?,
    ~onWidthChange: (
    (~containerWidth: int,
      ~margin: (int, int),
      ~cols: int,
      ~containerPadding: Js.Nullable.t((int, int)),
      unit
    ) => unit
    ) = ?,
    ~children: React.element = ?
  ) => React.element = "Responsive";