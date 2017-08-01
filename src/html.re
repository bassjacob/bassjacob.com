module Attr = {
  type t =
    | Style string
    | Class string
    | Id string
    | Data string string;

  let evalAttr = fun
    | Style s => {j|style="$(s)"|j}
    | Class c => {j|class="$(c)"|j}
    | Id i => {j|id="$(i)"|j}
    | Data s1 s2 => {j|data-$(s1)="$(s2)"|j};

  let rec eval = fun
    | [] => ""
    | [x, ...xs] => (evalAttr x) ^ " " ^ eval xs;

};

module Tag = {
  type t =
    | Section (list Attr.t) (list t)
    | Div (list Attr.t) (list t)
    | String string;

  let rec evalTag = fun
    | String str => str
    | Section attrs inner => stringifyTag "section" attrs inner
    | Div attrs inner => stringifyTag "div" attrs inner
  and stringifyTag tag attrs inner => {
    let x = eval inner;
    let y = Attr.eval attrs;
    {j|<$(tag) $(y)>$(x)</$(tag)>|j}
  }
  and eval = fun
    | [] => ""
    | [x, ...xs] => (evalTag x) ^ eval xs;
};


let controller _ res _ => {
  open Tag;

  let html = [
    Section [] [
      Section [] [
        Div [Style "background:red"] [ (String "hello world") ],
        String "goodbye world"
      ]
    ]
  ];

  Server.send res @@ Tag.eval html;
};
