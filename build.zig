const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});

    const optimize = b.standardOptimizeOption(.{});

    const lib = b.addStaticLibrary(.{
        .name = "gtk++",
        .target = target,
        .optimize = optimize,
    });
    lib.addCSourceFiles(.{ .files = &.{
        "src/widget.cc",
        "src/application.cc",
        "src/container.cc",
        "src/window.cc",
        "src/button.cc",
        "src/grid.cc",
        "src/object.cc",
        "src/builder.cc"
    }, .flags = &.{ "-std=c++11"}});
    lib.addIncludePath(b.path("include"));
    lib.linkLibCpp();
    lib.linkSystemLibrary("gtk+-3.0");
    lib.linkSystemLibrary("gobject-2.0");

    b.installArtifact(lib);

    const example = b.option([]const u8, "example", "Build hello example.") orelse "hello";

    const exe = b.addExecutable(.{
        .name = example,
        .target = target,
        .optimize = optimize,
    });
    exe.addCSourceFile( .{ .file = b.path(b.fmt("examples/{s}.cc", .{example}))} );
    exe.addIncludePath(b.path("include"));
    exe.linkLibCpp();
    exe.linkLibrary(lib);
    lib.linkSystemLibrary("gtk+-3.0");
    lib.linkSystemLibrary("gobject-2.0");
    
    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);

    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the examples");
    run_step.dependOn(&run_cmd.step);

}
