type route =
  | ErrorRoute errorMiddlewareFn
  | Route (method, string, middlewareFn)
  | Use middlewareFn;
