program tstringbuilder_test;

{$mode objfpc}{$H+}

uses
  Interfaces, Forms, GUITestRunner, tstringbuildercases;

{$R *.res}

begin
  Application.Initialize;
  RunRegisteredTests;
end.

