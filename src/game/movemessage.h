//
// Created by joris on 20.08.19.
//
#pragma once
#include <string>
#include <memory>
#include "piece.h"

class MoveMessage
{
public:
    explicit MoveMessage(const std::shared_ptr<chess::Piece> selected_piece);
    MoveMessage(std::shared_ptr<chess::Piece> selected_piece,
                std::shared_ptr<chess::Piece> taken_piece,
                std::string from,
                std::string to);
    MoveMessage(std::shared_ptr<chess::Piece> selected_piece, std::string from, std::string to);
    MoveMessage() = default;
    virtual bool is_valid_move();
    virtual std::string get_message();
    virtual ~MoveMessage() = default;
protected:
    std::shared_ptr<chess::Piece> m_selected_piece = nullptr;
    std::shared_ptr<chess::Piece> m_taken_piece = nullptr;
    std::string m_from;
    std::string m_to;
};

class InvalidMoveMessageNoMovement: public MoveMessage
{


    // MoveMessage interface
public:
    std::string get_message() override;
    bool is_valid_move() override;
};

class InvalidMoveMessageNothingMoved: public MoveMessage
{
public:
    std::string get_message() override;
    bool is_valid_move() override;
};

class InvalidMoveMessageWrongColor: public MoveMessage
{
public:
    explicit InvalidMoveMessageWrongColor(const std::shared_ptr<chess::Piece> &selected_piece);
    std::string get_message() override;
    bool is_valid_move() override;
};

class InvalidMoveMessageOutsideOfBoard: public MoveMessage
{
public:
    explicit InvalidMoveMessageOutsideOfBoard(const std::shared_ptr<chess::Piece> &selected_piece);


    // MoveMessage interface
public:
    bool is_valid_move() override;
    std::string get_message() override;
};

class InvalidMoveMessageOutOfRange: public MoveMessage
{

public:
    explicit InvalidMoveMessageOutOfRange(const std::shared_ptr<chess::Piece> &selected_piece);
    // MoveMessage interface
public:
    bool is_valid_move() override;
    std::string get_message() override;
};

class InvalidMoveMessageIllegalMove: public MoveMessage
{
public:
    explicit InvalidMoveMessageIllegalMove(const std::shared_ptr<chess::Piece> &selected_piece);
    // MoveMessage interface
public:
    bool is_valid_move() override;
    std::string get_message() override;
};

class InvalidMoveMessageCollision: public MoveMessage
{


    // MoveMessage interface
public:
    bool is_valid_move() override;
    std::string get_message() override;
};

class ValidMoveMessage: public MoveMessage
{


    // MoveMessage interface
public:
    bool is_valid_move() override;
};

class ValidMoveMessageEnPassant: public MoveMessage
{
public:
    bool is_valid_move() override;
    std::string get_message() override;
};

class ValidMoveMessagePieceTaken: public MoveMessage
{

public:
    ValidMoveMessagePieceTaken(const std::shared_ptr<chess::Piece> &selected_piece,
                               const std::shared_ptr<chess::Piece> &taken_piece,
                               const std::string &from,
                               const std::string &to);
    // MoveMessage interface
public:
    bool is_valid_move() override;
    std::string get_message() override;
};

class ValidMoveMessageJustMoved: public MoveMessage
{
public:
    ValidMoveMessageJustMoved(const std::shared_ptr<chess::Piece> &selected_piece,
                              const std::string &from,
                              const std::string &to);

    // MoveMessage interface
public:
    bool is_valid_move() override;
    std::string get_message() override;
};
