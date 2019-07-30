[@bs.module "react-grid-layout"][@react.element]
external make :
  (~className: option(string) = ?,
    ~measureBeforeMount: bool,
    ~style: option(Js.t({..})) = ?
  ) => React.element = "WidthProvider";