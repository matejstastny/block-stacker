## VSCode user settings to make Vex VSCode extension work

> [!WARNING]
> I haven't worked with vex since this repo was created. The extension was in early development back then so this could be completely outdated!!!

 The extension for VexV5 for VSCode is funky. You don't need it if you do not want to upload this code to an actual Vex robot, but if you do you need to do this to make it work. There has to be some specific settings in the user VSCode `settings.json` file:

```json
"vexrobotics.vexcode.Project.Home": "/Users/matejstastny/Documents/vex-vscode-projects",
"vexrobotics.vexcode.Cpp.Sdk.Home": "/Users/matejstastny/Library/Application Support/Code/User/globalStorage/vexrobotics.vexcode/sdk/cpp",
"vexrobotics.vexcode.General.EnableUserTerminal": "Disable",
"makefile.configureOnOpen": true,
"vexrobotics.vexcode.Cpp.Toolchain.Path": "/Users/matejstastny/Library/Application Support/Code/User/globalStorage/vexrobotics.vexcode/tools/cpp/toolchain_osxarm64",
```

> [!NOTE]
> Replace `/Users/matejstastny` with your actual home path

> [!WARNING]
> These paths are tested on MacOS!! It won't work on other OS (propably, idk)
> Also you MUST use absolute paths, so no `~` or `$HOME`. Yes, I know, it sucks...
