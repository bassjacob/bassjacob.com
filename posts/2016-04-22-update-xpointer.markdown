---
title: UpdatePointer in XMonad Contrib v0.12
summary: How to fix a `Not in scope data constructor 'Relative'` error in XMonad Contrib Actions UpdatePointer v0.12
---

The time came to replace an ailing macbook air with a new machine, and I've chosen a Lenovo. Now that I have something that uses an Intel WiFi chip, I'm much happier to take a shot at running Arch Linux, and I thought while I was undergoing this change I would switch from i3wm to xmonad.

However, as part of the setup I wanted the mouse to follow the window focus, which is provided by the [XMonad-Contrib](http://xmonad.org/xmonad-docs/xmonad-contrib/). At the time of writing, the version in the ArchLinux repository is 0.12, but the documentation is for the 0.11 release. This means that the advice on the [XMonad.Actions.UpdatePointer](http://xmonad.org/xmonad-docs/xmonad-contrib/XMonad-Actions-UpdatePointer.html) page is invalid, since there was a breaking change to the API the PointerPosition data constructor uses to position the cursor.

This lead to me getting a very confusing error: Not in scope: data constructor 'Relative', the fix for which is outlined in the [source code](https://github.com/xmonad/xmonad-contrib/blob/master/XMonad/Actions/UpdatePointer.hs#L40), and reproduced below for convenience.


```haskell
-- nearest point of window
logHook = updatePointer (0.5, 0.5) (1, 1)
-- exact centre of window
logHook = updatePointer (0.5, 0.5) (0, 0)
-- near the top-left
logHook = updatePointer (0.25, 0.25) (0.25, 0.25)
-- within 110% of the edge
logHook = updatePointer (0.5, 0.5) (1.1, 1.1)
```

This syntax replaces the previous use of the data constructors (Nearest, Relative and TowardsCentre);

