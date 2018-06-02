open ReactGrid;

let component = ReasonReact.statelessComponent("MyFirstGrid");

let make(children) {
  ...component,
  render: (self) => {
    let layout = [|
      layout(~i="a", ~x=0, ~y=0, ~w=1, ~h=1, ~static=true, ()),
      layout(~i="b", ~x=1, ~y=0, ~w=3, ~h=2, ~minW=2, ~maxW=4, ()),
      layout(~i="c", ~x=4, ~y=0, ~w=1, ~h=2, ())
    |];
    <ReactGridLayout className="layout" layout cols=12 rowHeight=30 width=100>
      <GridItem>
        <div key="a"> (ReasonReact.stringToElement("a")) </div>
      </GridItem>
      <div key="b"> (ReasonReact.stringToElement("b")) </div>
      <div key="c"> (ReasonReact.stringToElement("c")) </div>
    </ReactGridLayout>;
  }
};
