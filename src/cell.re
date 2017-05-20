module Helpers = {
  external fromPromiseError: Js_promise.error => Express.Error.t = "%identity";

  let promiseControllerErrorHandler next => {
    Js_promise.catch (fun z => {
      Js.log z;
      z |> fromPromiseError
      |> Express.Next.error
      |> next
      |> Js.Promise.resolve
    });
  };
};
