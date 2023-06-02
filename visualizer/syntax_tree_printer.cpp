//
// Created by 刘宇轩 on 2023/5/15.
//

#include "syntax_tree_printer.h"

void SyntaxTreePrinter::PrintTree(std::ostream &out) {
    if (root_ == nullptr) {
        out << "digraph G{ }" << std::endl;
        return;
    }
    out << "digraph G{ " << std::endl;
    PrintTreeLow(root_, out);
    out << "}" << std::endl;
}

void SyntaxTreePrinter::PrintTreeLow(pAstNode node, std::ostream &out) {
    out << "SYNTAX_NODE_" << node->id_ << "[label=\"";
    out << GetSyntaxNodeTypeStr(node->type_) << "(" << node->line_no_ << "," << node->col_no_ << ")";
    out << "\\n";
    out << "id(" << node->id_ << ")";
    if (node->val_ != nullptr && node->type_ != kStrLiteral) {
        out << ",val(" << node->val_ << ")";
    } else if(node->type_ == kStrLiteral) {
        std::string view = std::string{node->val_ + 1, strlen(node->val_) - 2};
        out << ",val(" << view << ")";
    }
    out << "\"];" << std::endl;

    if (node->child_ != nullptr) {
        PrintTreeLow(node->child_, out);
        out << "SYNTAX_NODE_" << node->id_ << "  ->  " << "SYNTAX_NODE_" << node->child_->id_ << ";" << std::endl;
    }

    if (node->next_ != nullptr) {
        PrintTreeLow(node->next_, out);
        out << "SYNTAX_NODE_" << node->id_ << "  ->  " << "SYNTAX_NODE_" << node->next_->id_ << ";" << std::endl;
        out << "{rank=same; " << "SYNTAX_NODE_" << node->id_ << "," << "SYNTAX_NODE_" << node->next_->id_ << "};"
            << std::endl;
    }

}

