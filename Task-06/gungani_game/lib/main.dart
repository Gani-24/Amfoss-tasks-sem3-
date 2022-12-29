import 'package:flame/game.dart';
import 'package:flame/palette.dart';
import 'package:flutter/material.dart';
import 'package:flame/flame.dart';
import 'package:flame/game.dart';
import 'package:flame/input.dart';
import 'package:flame/components.dart';
import 'package:flutter/services.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  SystemChrome.setPreferredOrientations([DeviceOrientation.landscapeLeft])
      .then((_) {
    runApp(GameWidget(game: MyGame()));
  });
}

class MyGame extends FlameGame
    with HasTappables, HasDraggables, HasCollisionDetection {
  SpriteComponent gunnesh = SpriteComponent();
  SpriteComponent back = SpriteComponent();
  late JoystickComponent joystick;
  @override
  Future<void> onLoad() async {
    await super.onLoad();
    back
      ..sprite = await loadSprite('background.png')
      ..size = size;
    add(back);
    gunnesh
      ..sprite = await loadSprite('bunny.png')
      ..size = Vector2.all(200)
      ..position = Vector2(80, 150);
    add(gunnesh);
    final knobPaint = BasicPalette.black.withAlpha(200).paint();
    final backgroundPaint = BasicPalette.white.withAlpha(100).paint();
    joystick = JoystickComponent(
      knob: CircleComponent(radius: 10, paint: knobPaint),
      background: CircleComponent(radius: 50, paint: backgroundPaint),
      margin: const EdgeInsets.only(left: 40, bottom: 40),
    );
    add(joystick);
  }

  @override
  void update(double dt) {
    super.update(dt);
    gunnesh.position.add(joystick.relativeDelta * 300 * dt);
    //back.position.add(joystick.relativeDelta * 100 * dt);
  }
}
