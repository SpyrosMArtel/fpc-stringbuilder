// TStringBuilder implementation for Free  Pascal
// Copyright (c) 2013 Michal J Wallace < http://tangentstorm.com/ >
// LICENSE: your choice of either:
// - MIT/X11 license
// - FPC license (GNU LGPL with static linking allowance).
constructor TStringBuilder.Create;
  begin
   inherited Create;
   Create(1024); // default capacity
  end;

constructor TStringBuilder.Create(aCapacity: Integer);
  begin
    inherited Create;
    if aCapacity < 0 then raise ERangeError.Create('aCapacity < 0');
    if aCapacity > Integer.MaxValue then raise ERangeError.Create('aCapacity > Integer.MaxValue');

    if aCapacity = 0 then begin
      Capacity := 1024;
    end
    else begin
      Capacity := aCapacity;
    end;
    Getmem(fData, Capacity);
    fMaxCapacity := Integer.MaxValue;
    fLength := 0;
  end;

constructor TStringBuilder.Create(const Value: string);
  begin
    Create(1024);
    Append(Value);
  end;

constructor TStringBuilder.Create(aCapacity: Integer; aMaxCapacity: Integer);
  begin
    Create(aCapacity);

    if aMaxCapacity < 0 then raise ERangeError.Create('aMaxCapacity < 0');
    if aMaxCapacity > Integer.MaxValue then raise ERangeError.Create('aMaxCapacity > Integer.MaxValue');

    fMaxCapacity := aMaxCapacity;
  end;

constructor TStringBuilder.Create(const Value: string; aCapacity: Integer);
  begin
    inherited Create;
    if aCapacity < 0 then raise ERangeError.Create('aCapacity < 0');
    if aCapacity > Integer.MaxValue then raise ERangeError.Create('aCapacity > Integer.MaxValue');

    if aCapacity = 0 then begin
      Capacity := 1024;
    end
    else begin
      Capacity := aCapacity;
    end;
    Getmem(fData, Capacity);
    fMaxCapacity := Integer.MaxValue;
    fLength := 0;
    Append(Value);
  end;

constructor TStringBuilder.Create(const Value: string; StartIndex: Integer; Length: Integer; aCapacity: Integer);
  begin
    Create(Value.Substring(StartIndex, Length), aCapacity);
  end;

destructor TStringBuilder.Destroy;
  begin
    Freemem(fData);
    Inherited Destroy;
  end;

function TStringBuilder.GetCapacity : Integer;
  begin
    result := fCapacity;
  end;

function TStringBuilder.GetMaxCapacity : Integer;
  begin
    result := fMaxCapacity;
  end;

function TStringBuilder.GetLength : Integer;
  begin
    result := fLength;
  end;

procedure TStringBuilder.SetCapacity(const Value : Integer);
  begin
    fCapacity := Value;
  end;

procedure TStringBuilder.SetMaxCapacity(const Value : Integer);
  begin
    fMaxCapacity := Value;
  end;

procedure TStringBuilder.SetLength(const Value : Integer);
  begin
    fLength := Value;
  end;

function TStringBuilder.GetChar(const index : Integer) : char;
  begin
    if index < 0 then raise ERangeError.Create('index < 0');
    if index > fLength then raise ERangeError.Create('index > Length');
    result := fData[index];
  end;

procedure TStringBuilder.SetChar(const index : Integer; const Value : char);
  begin
  end;

procedure TStringBuilder.Grow();
  begin
    Capacity := Capacity shl 1;
    if (Capacity > fMaxCapacity) then
        Capacity := fMaxCapacity;
    if (Capacity < 0) then
        Capacity := fLength;

    ReAllocMem(fData, Capacity);
  end;

procedure TStringBuilder.Shrink();
begin
  Capacity := Capacity shr 1;
  if (fLength > Capacity) then
      Capacity := fLength;

  ReAllocMem(fData, Capacity);
end;

function TStringBuilder.Append(const Value: ShortString): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;


function TStringBuilder.Append(const Value: AnsiString): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Boolean): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Byte): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Char): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Currency): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Double): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Smallint): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Integer): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Int64): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: TObject): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Shortint): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Single): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: UInt64): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: TCharArray): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Word): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Cardinal): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: PAnsiChar): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: Char; RepeatCount: Integer): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: TCharArray; StartIndex: Integer; CharCount: Integer): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.Append(const Value: string; StartIndex: Integer; Count: Integer): TStringBuilder;
  begin
    result := self.Insert(self.Length, Value)
  end;

function TStringBuilder.AppendFormat(const Format: string; const Args: array of const): TStringBuilder;
  begin
    Append(SysUtils.Format(Format, Args));
    result := self
  end;

function TStringBuilder.AppendLine: TStringBuilder;
  begin
    Append(system.LineEnding);
    result := self
  end;

function TStringBuilder.AppendLine(const Value: string): TStringBuilder;
  begin
    Append(Value);
    result := self
  end;

procedure TStringBuilder.Clear;
  begin
    self.Length := 0;
    Capacity := 1024;
    ReAllocMem(fData, Capacity);
  end;

procedure TStringBuilder.CopyTo(SourceIndex: Integer; const Destination: TCharArray; DestinationIndex: Integer; Count: Integer);
  begin
  end;

function TStringBuilder.EnsureCapacity(aCapacity: Integer): Integer;
  begin
    result := 0
  end;

function TStringBuilder.Equals(StringBuilder: TStringBuilder): Boolean;
  begin
    result := false
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Boolean): TStringBuilder;
  var boolTrue : string;
      boolFalse: string;
  begin
    if Value then begin
      boolTrue := 'True';
      result := Insert(Index, boolTrue);
    end else begin
      boolFalse := 'False';
      result := Insert(Index, boolFalse);
    end;
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Byte): TStringBuilder;
begin
  result := Insert(Index, IntToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: Char): TStringBuilder;
  var sLen : Integer;
  begin
    sLen := SizeOf(Char);
    if (fLength + sLen) > Capacity-1 then Grow;
    Move(Value, fData[fLength], sLen);
    Inc(fLength, sLen);
    result := self
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Currency): TStringBuilder;
  begin
    result := Insert(Index, CurrToStr(Value));
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Double): TStringBuilder;
begin
  result := Insert(Index, FloatToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: Smallint): TStringBuilder;
begin
   result := Insert(Index, IntToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: Integer): TStringBuilder;
begin
  result := Insert(Index, IntToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: TCharArray): TStringBuilder;
  var sLen : Integer;
  begin
    sLen := self.Length + system.Length(Value);
    if (slen + fLength) > Capacity-1 then Grow;
    Move(Value[0], fData[fLength], sLen);
    Inc(fLength, sLen);
    result := self
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Int64): TStringBuilder;
begin
   result := Insert(Index, IntToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: TObject): TStringBuilder;
  begin
    if (Value = nil) then begin
      result := Append('Nil');
    end else begin
      result := Insert(Index, Value.ToString);
    end;
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Shortint): TStringBuilder;
begin
 result := Insert(Index, IntToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: Single): TStringBuilder;
begin
  result := Insert(Index, FloatToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: string): TStringBuilder;
 var sLen : integer;
 begin
    sLen := system.Length(Value);
    if (slen + fLength) > Capacity-1 then Grow;
    Move(Value[1], fData[Index], sLen);
    Inc(fLength, sLen);
    result := self;
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Word): TStringBuilder;
  begin
    result := self;
  end;

function TStringBuilder.Insert(Index: Integer; const Value: Cardinal): TStringBuilder;
begin
  result := Insert(Index, IntToStr(Value));
end;

function TStringBuilder.Insert(Index: Integer; const Value: UInt64): TStringBuilder;
  begin
    result := Insert(Index, IntToStr(Value));
  end;

function TStringBuilder.Insert(Index: Integer; const Value: string; count: Integer): TStringBuilder;
  begin
    result := self;
  end;

function TStringBuilder.Insert(Index: Integer; const Value: TCharArray; startIndex: Integer; charCount: Integer): TStringBuilder;
  begin
    result := self;
  end;

function TStringBuilder.Remove(StartIndex: Integer; RemLength: Integer): TStringBuilder;
  var srcStartPos : Integer;
      count : Integer;
  begin
    if (StartIndex < 0) then begin
     raise ERangeError.Create('Startindex : ' + IntToStr(StartIndex));
    end;
    if (RemLength < 0) then begin
     raise ERangeError.Create('RemLength < 0');
    end;
    if (StartIndex > fLength) then begin
     raise ERangeError.Create('StartIndex > Length');
    end;
    if (((StartIndex + RemLength) - 1) > fLength) then begin
     raise ERangeError.Create('StartIndex + RemLength > Length');
    end;

    srcStartPos := StartIndex + RemLength;
    count := fLength - srcStartPos;
    if count > 0 then Move(fData[srcStartPos], fData[StartIndex], count * SizeOf(Char));
    fLength := fLength - RemLength;

    self.Shrink();
    result := self;
  end;

function TStringBuilder.Replace(const OldChar: Char; const NewChar: Char): TStringBuilder;
  begin
    result := self;
  end;

function TStringBuilder.Replace(const OldValue: string; const NewValue: string): TStringBuilder;
var sbToString : string;
begin
  sbToString := self.ToString;
  sbToString := StringReplace(sbToString, OldValue, NewValue, [rfReplaceAll]);
  self.Clear;
  result := Insert(0, sbToString);
  end;

function TStringBuilder.Replace(const OldChar: Char; const NewChar: Char; StartIndex: Integer; Count: Integer): TStringBuilder;
  begin
    if StartIndex < 0 then
      raise ERangeError.Create('Startindex is out of bounds!');

    if StartIndex + Count > fLength then
      raise ERangeError.Create('Startindex + Count > Length');

    result := self;
  end;

function TStringBuilder.Replace(const OldValue: string; const NewValue: string; StartIndex: Integer; Count: Integer): TStringBuilder;
  begin
    if StartIndex < 0 then
      raise ERangeError.Create('Startindex is out of bounds!');

    if StartIndex + Count > fLength then
      raise ERangeError.Create('Startindex + Count > Length');

    result := self;
  end;

function TStringBuilder.ToString: string;
  begin
    fData[fLength] := #0;
    result := fData;
  end;

function TStringBuilder.ToString(StartIndex: Integer; StrLength: Integer): string;
  begin
    if StartIndex < 0 then raise ERangeError.Create('Startindex < 0');
    if StartIndex > fLength then raise ERangeError.Create('Startindex > Length');

    fData[fLength] := #0;
    result := Copy(fdata, StartIndex, StrLength);
  end;
