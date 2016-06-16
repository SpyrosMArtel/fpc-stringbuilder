unit tstringbuildercases;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, TestFramework, ustringbuilder;

type

  TStringBuilderCase = class(TTestCase)
  private
    stringbuilder : TStringBuilder;
  published
    procedure TestInit;
    procedure TestAppendBoolean;

    procedure TestAppendCurrency;
    procedure TestAppendDouble;
    procedure TestAppendInteger;
    procedure TestAppendSmallInt;
    procedure TestAppendInt64;
    procedure TestAppendShortint;
    procedure TestAppendSingle;
    procedure TestAppendUInt64;

    procedure TestAppendString;
    procedure TestAppendTCharArray;
    procedure TestAppendChar;

    procedure TestAppendByte;

    procedure TestAppendObject;
    procedure TestClear;
    procedure TestRemove;
    procedure TestReplaceOldNew;
    procedure TestGetChar;
  end;

implementation

procedure TStringBuilderCase.TestInit;
begin
  stringbuilder := TStringBuilder.Create;
  AssertEquals('Length must be zero', 0,stringbuilder.Length);
  AssertEquals('Maximum capacity must be Integer.MaxValue', Integer.MaxValue,stringbuilder.MaxCapacity);
end;
{-------------------------------------------------------------------------------
Boolean testing
-------------------------------------------------------------------------------}
procedure TStringBuilderCase.TestAppendBoolean;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append(True);
  AssertEquals('Stringbuilder must be True', 'True', stringbuilder.ToString);
  stringbuilder.Clear;
  stringbuilder.Append(False);
  AssertEquals('Stringbuilder must be False', 'False',stringbuilder.ToString);
  stringbuilder.Free;
end;
{-------------------------------------------------------------------------------
Number testing
-------------------------------------------------------------------------------}
procedure TStringBuilderCase.TestAppendCurrency;
 var myCurr : Currency;
begin
  stringbuilder := TStringBuilder.Create;
  myCurr := 999912.1221;
  stringbuilder.Append(myCurr);
  AssertEquals('Stringbuilder must be 3,14159265358979', FloatToStr(myCurr), stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendDouble;
 var myDouble : Double;
begin
  stringbuilder := TStringBuilder.Create;
  myDouble := 3.14159265358979;
  stringbuilder.Append(myDouble);
  AssertEquals('Stringbuilder must be 3,14159265358979', FloatToStr(myDouble), stringbuilder.ToString);
  stringbuilder.Clear;
  myDouble := (Double.MaxValue + 1.0);
  stringbuilder.Append(myDouble);
  AssertEquals('Stringbuilder must be equal to Double.MaxValue', FloatToStr(Double.MaxValue), stringbuilder.ToString);
  stringbuilder.Clear;
  myDouble := (Double.MinValue - 1.0);
  stringbuilder.Append(myDouble);
  AssertEquals('Stringbuilder must be equal to Double.MinValue', FloatToStr(Double.MinValue), stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendSmallInt;
var si : SmallInt;
begin
  stringbuilder := TStringBuilder.Create;
  si := 200;
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be "200"', '200', stringbuilder.ToString);
  stringbuilder.Clear;
  si := (SmallInt.MaxValue + 10);
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be equal to SmallInt.MinValue', IntToStr(SmallInt.MinValue + 9), stringbuilder.ToString);
  stringbuilder.Clear;
  si := (SmallInt.MinValue - 10);
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be equal to SmallInt.MaxValue', IntToStr(SmallInt.MaxValue - 9), stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendInt64;
var largeInt : Int64;
begin
  stringbuilder := TStringBuilder.Create;
  largeInt := 9887766554433221;
  stringbuilder.Append(largeInt);
  AssertEquals('Stringbuilder must be "9887766554433221"', '9887766554433221', stringbuilder.ToString);
  stringbuilder.Clear;
  largeInt := (Int64.MaxValue + 10);
  stringbuilder.Append(largeInt);
  AssertEquals('Stringbuilder must be equal to Int64.MinValue + 9', IntToStr(Int64.MinValue + 9), stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendInteger;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append(123456789);
  AssertEquals('Stringbuilder must be "123456789"', '123456789', stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendShortint;
var si : ShortInt;
begin
  stringbuilder := TStringBuilder.Create;
  si := 126;
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be "126"', '126', stringbuilder.ToString);
  si := ShortInt.MinValue;
  stringbuilder.Clear;
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be ShortInt.MinValue', IntToStr(ShortInt.MinValue), stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendSingle;
var si : Single;
begin
  stringbuilder := TStringBuilder.Create;
  si := Single.MaxValue;
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be "Single.MaxValue"', FloatToStr(Single.MaxValue), stringbuilder.ToString);
  si := Single.MinValue;
  stringbuilder.Clear;
  stringbuilder.Append(si);
  AssertEquals('Stringbuilder must be Single.MinValue', FloatToStr(Single.MinValue), stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendUInt64;
var uinteger64 : UInt64;
begin
  stringbuilder := TStringBuilder.Create;
  uinteger64 := 98877665433224;
  stringbuilder.Append(uinteger64);
  AssertEquals('Stringbuilder must be "98877665433224"', '98877665433224', stringbuilder.ToString);
  uinteger64 := UInt64.MaxValue;
  stringbuilder.Clear;
  stringbuilder.Append(uinteger64);
  AssertEquals('Stringbuilder must be UInt64.MaxValue', IntToStr(UInt64.MaxValue), stringbuilder.ToString);
  stringbuilder.Free;
end;
{-------------------------------------------------------------------------------
text testing
-------------------------------------------------------------------------------}
procedure TStringBuilderCase.TestAppendString;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append('Hello Test');
  AssertEquals('Stringbuilder must be "Hello Test"', 'Hello Test', stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendTCharArray;
var alphabet : TCharArray;
begin
  stringbuilder := TStringBuilder.Create;
  SetLength(alphabet, 5);
  alphabet[0] := 'a';
  alphabet[1] := 'b';
  alphabet[2] := 'c';
  alphabet[3] := 'd';
  stringbuilder.Append(alphabet);
  AssertEquals('Stringbuilder must be "abcd"', 'abcd', stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendChar;
 var testChar : Char;
begin
  stringbuilder := TStringBuilder.Create;
  testChar := '!';
  stringbuilder.Append(testChar);
  AssertEquals('Stringbuilder must be "!"', '!', stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestAppendByte;
 var testChar : Byte;
begin
  stringbuilder := TStringBuilder.Create;
  testChar := 77;
  stringbuilder.Append(testChar);
  AssertEquals('Stringbuilder must be "77"', '77', stringbuilder.ToString);
  stringbuilder.Free;
end;
{-------------------------------------------------------------------------------
object testing
-------------------------------------------------------------------------------}
procedure TStringBuilderCase.TestAppendObject;
 var testObj : TStringBuilder;
begin
  stringbuilder := TStringBuilder.Create;
  testObj := TStringBuilder.Create;
  stringbuilder.Append(testObj);
  AssertEquals('Stringbuilder must be ""', '', stringbuilder.ToString);
  testObj.Free;
  testObj := Nil;
  stringbuilder.Append(testObj);
  AssertEquals('Stringbuilder must be "Nil"', 'Nil', stringbuilder.ToString);
  stringbuilder.Free;
end;
{-------------------------------------------------------------------------------
other functions testing
-------------------------------------------------------------------------------}
procedure TStringBuilderCase.TestRemove;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append('A simple buffer like this and something even more texty.');
  stringbuilder.Remove(1, 7);
  AssertEquals('Stringbuilder must be "A buffer like this and something even more texty."',
                              'A buffer like this and something even more texty.', stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestClear;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append('Some Data goes here');
  stringbuilder.Clear;
  AssertEquals('Stringbuilder must be ""', '', stringbuilder.ToString);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestReplaceOldNew;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append('Some Data goes here');
  stringbuilder.Replace(' goes', '');
  AssertEquals('Stringbuilder must be "Some Data here"', 'Some Data here', stringbuilder.ToString);
  AssertEquals('The String length in the stringbuilder must equal its lenght', Length('Some Data here'), stringbuilder.Length);
  stringbuilder.Free;
end;
procedure TStringBuilderCase.TestGetChar;
begin
  stringbuilder := TStringBuilder.Create;
  stringbuilder.Append('ABCD!@');
  AssertEquals('Chars[1] must be "A"', 'A', stringbuilder.Chars[0]);
  AssertEquals('Chars[2] must be "B"', 'B', stringbuilder.Chars[1]);
  AssertEquals('Chars[3] must be "C"', 'C', stringbuilder.Chars[2]);
  AssertEquals('Chars[4] must be "D"', 'D', stringbuilder.Chars[3]);
  AssertEquals('Chars[5] must be "!"', '!', stringbuilder.Chars[4]);
  AssertEquals('Chars[6] must be "@"', '@', stringbuilder.Chars[5]);
  stringbuilder.Free;
end;
initialization
  RegisterTest(TStringBuilderCase.Suite);
end.

